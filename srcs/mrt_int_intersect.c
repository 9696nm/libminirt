/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:55:19 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/08/26 14:51:57 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_int.h"
#include "utils_render.h"

int	mrt_int_intersect_search(t_scene *scene, t_ray *ray)
{
	float			t;
	unsigned int	index;

	ray->colision = NULL;
	ray->distance = FLT_MAX;
	index = 0;
	while (index < scene->num_obj)
	{
		t = scene->objects[index]->intersect(ray, scene->objects[index]);
		if (0.0f + FLT_EPSILON < ray->distance && t < ray->distance)
		{
			ray->distance = t;
			ray->colision = scene->objects[index];
		}
		index++;
	}
	if (ray->colision == NULL)
		return (false);
	return (true);
}

float	mrt_int_intersect_sp(const t_ray *ray, void *obj)
{
	t_obj_sph	*sphere;
	t_vec3		oc;
	float		b;
	float		disc;
	float		t;

	sphere = (t_obj_sph *)obj;
	oc = vec3_sub(
			coord_to_vec3(ray->cam->pos), coord_to_vec3(sphere->base.pos));
	b = 2.0f * vec3_dot(ray->raycast, oc);
	disc = b * b - 4.0f * vec3_dot(ray->raycast, ray->raycast)
		* (vec3_dot(oc, oc) - sphere->r * sphere->r);
	if (disc < 0.0)
		return (FLT_MAX);
	disc = sqrtf(disc);
	t = (-b - disc) / (2.0f * vec3_dot(ray->raycast, ray->raycast));
	if (t < FLT_EPSILON)
	{
		t = (-b + disc) / (2.0f * vec3_dot(ray->raycast, ray->raycast));
		if (t < FLT_EPSILON)
			return (FLT_MAX);
	}
	return (t);
}

float	mrt_int_intersect_pl(const t_ray *ray, void *obj)
{
	t_obj_pln	*plane;
	float		normal_dot_raycast;
	float		t;

	plane = (t_obj_pln *)obj;

	normal_dot_raycast = vec3_dot(plane->normal, ray->raycast);
	if (fabsf(normal_dot_raycast) < FLT_EPSILON)
		return (FLT_MAX);
	t = (vec3_dot(plane->normal, coord_to_vec3(plane->base.pos))
		- vec3_dot(plane->normal, coord_to_vec3(ray->cam->pos)))
		/ normal_dot_raycast;
	if (t < FLT_EPSILON)
		return (FLT_MAX);
	return (t);
}

static float	mrt_int_intersect_cy_side(const t_ray *ray, t_obj_cyl *cylinder)
{
	t_vec3	oc;
	t_vec3	ray_cross_axis;
	t_vec3	oc_cross_axis;
	float	a;
	float	b;
	float	c;
	float	disc;
	float	t;
	float	radius;

	radius = cylinder->d / 2.0f;
	oc = vec3_sub(coord_to_vec3(ray->cam->pos), coord_to_vec3(cylinder->base.pos));
	ray_cross_axis = vec3_cross(ray->raycast, cylinder->axis);
	oc_cross_axis = vec3_cross(oc, cylinder->axis);
	
	a = vec3_dot(ray_cross_axis, ray_cross_axis);
	b = 2.0f * vec3_dot(ray_cross_axis, oc_cross_axis);
	c = vec3_dot(oc_cross_axis, oc_cross_axis) - radius * radius;
	
	disc = b * b - 4.0f * a * c;
	if (disc < 0.0f)
		return (FLT_MAX);
	
	disc = sqrtf(disc);
	t = (-b - disc) / (2.0f * a);
	if (t < FLT_EPSILON)
	{
		t = (-b + disc) / (2.0f * a);
		if (t < FLT_EPSILON)
			return (FLT_MAX);
	}
	return (t);
}

static float	mrt_int_intersect_cy_cap(const t_ray *ray, t_obj_cyl *cylinder, int is_top)
{
	t_vec3	cap_center;
	t_vec3	cap_normal;
	float	normal_dot_raycast;
	float	t;
	t_vec3	hit_point;
	t_vec3	cap_to_hit;
	float	dist_sq;
	float	radius;

	radius = cylinder->d / 2.0f;
	if (is_top)
	{
		cap_center = vec3_add(coord_to_vec3(cylinder->base.pos), 
			vec3_scale(cylinder->axis, (float)cylinder->h));
		cap_normal = cylinder->axis;
	}
	else
	{
		cap_center = coord_to_vec3(cylinder->base.pos);
		cap_normal = vec3_scale(cylinder->axis, (float)(-1.0f));
	}
	
	normal_dot_raycast = vec3_dot(cap_normal, ray->raycast);
	if (fabsf(normal_dot_raycast) < FLT_EPSILON)
		return (FLT_MAX);
	
	t = vec3_dot(cap_normal, vec3_sub(cap_center, coord_to_vec3(ray->cam->pos))) 
		/ normal_dot_raycast;
	if (t < FLT_EPSILON)
		return (FLT_MAX);
	
	hit_point = vec3_add(coord_to_vec3(ray->cam->pos), vec3_scale(ray->raycast, (float)t));
	cap_to_hit = vec3_sub(hit_point, cap_center);
	dist_sq = vec3_dot(cap_to_hit, cap_to_hit);
	
	if (dist_sq > radius * radius)
		return (FLT_MAX);
	
	return (t);
}

float	mrt_int_intersect_cy(const t_ray *ray, void *obj)
{
	t_obj_cyl	*cylinder;
	float		t_side;
	float		t_top;
	float		t_bottom;
	float		t_min;
	t_vec3		hit_point;
	t_vec3		cylinder_to_hit;
	float		height_projection;

	cylinder = (t_obj_cyl *)obj;
	
	// 側面との交差を計算
	t_side = mrt_int_intersect_cy_side(ray, cylinder);
	if (t_side != FLT_MAX)
	{
		// 交差点が円柱の高さ範囲内かチェック
		hit_point = vec3_add(coord_to_vec3(ray->cam->pos), vec3_scale(ray->raycast, (float)t_side));
		cylinder_to_hit = vec3_sub(hit_point, coord_to_vec3(cylinder->base.pos));
		height_projection = vec3_dot(cylinder_to_hit, cylinder->axis);
		
		if (height_projection >= 0.0f && height_projection <= cylinder->h)
		{
			t_min = t_side;
		}
		else
		{
			t_side = FLT_MAX;
			t_min = FLT_MAX;
		}
	}
	else
	{
		t_min = FLT_MAX;
	}
	
	// 上面・下面との交差を計算
	t_top = mrt_int_intersect_cy_cap(ray, cylinder, 1);
	t_bottom = mrt_int_intersect_cy_cap(ray, cylinder, 0);
	
	// 最も近い有効な交差点を選択
	if (t_top != FLT_MAX && (t_min == FLT_MAX || t_top < t_min))
		t_min = t_top;
	if (t_bottom != FLT_MAX && (t_min == FLT_MAX || t_bottom < t_min))
		t_min = t_bottom;
	
	return (t_min);
}
