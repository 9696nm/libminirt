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

static float	mrt_int_intersect_cy_side(const t_ray *ray, t_obj_cyl *cy)
{
	t_vec3		oc;
	t_vec3		ray_cross_axis;
	t_vec3		oc_cross_axis;
	t_quad_func	f;

	f.radius = cy->d / 2.0f;
	oc = vec3_sub(coord_to_vec3(ray->cam->pos),
			coord_to_vec3(cy->base.pos));
	ray_cross_axis = vec3_cross(ray->raycast, cy->axis);
	oc_cross_axis = vec3_cross(oc, cy->axis);
	f.a = vec3_dot(ray_cross_axis, ray_cross_axis);
	f.b = 2.0f * vec3_dot(ray_cross_axis, oc_cross_axis);
	f.c = vec3_dot(oc_cross_axis, oc_cross_axis) - f.radius * f.radius;
	f.disc = f.b * f.b - 4.0f * f.a * f.c;
	if (f.disc < 0.0f)
		return (FLT_MAX);
	f.disc = sqrtf(f.disc);
	f.t = (-f.b - f.disc) / (2.0f * f.a);
	if (f.t < FLT_EPSILON)
	{
		f.t = (-f.b + f.disc) / (2.0f * f.a);
		if (f.t < FLT_EPSILON)
			return (FLT_MAX);
	}
	return (f.t);
}

static void	get_cap_normal(t_vec3 *center,
		t_vec3 *normal, t_obj_cyl *cy, int is_top)
{
	if (is_top)
	{
		*center = vec3_add(coord_to_vec3(cy->base.pos),
				vec3_scale(cy->axis, (float)cy->h));
		*normal = cy->axis;
	}
	else
	{
		*center = coord_to_vec3(cy->base.pos);
		*normal = vec3_scale(cy->axis, (float)(-1.0f));
	}
}

static float	mrt_int_intersect_cy_cap(const t_ray *ray,
		t_obj_cyl *cy, int is_top)
{
	t_vec3		cap_center;
	t_vec3		cap_normal;
	t_cap_func	f;

	f.radius = cy->d / 2.0f;
	get_cap_normal(&cap_center, &cap_normal, cy, is_top);
	f.normal_dot_raycast = vec3_dot(cap_normal, ray->raycast);
	if (fabsf(f.normal_dot_raycast) < FLT_EPSILON)
		return (FLT_MAX);
	f.t = vec3_dot(cap_normal,
			vec3_sub(cap_center, coord_to_vec3(ray->cam->pos)))
		/ f.normal_dot_raycast;
	if (f.t < FLT_EPSILON)
		return (FLT_MAX);
	f.hit_point = vec3_add(coord_to_vec3(ray->cam->pos),
			vec3_scale(ray->raycast, (float)f.t));
	f.cap_to_hit = vec3_sub(f.hit_point, cap_center);
	f.dist_sq = vec3_dot(f.cap_to_hit, f.cap_to_hit);
	if (f.dist_sq > f.radius * f.radius)
		return (FLT_MAX);
	return (f.t);
}

float	mrt_int_intersect_cy(const t_ray *ray, void *obj)
{
	t_obj_cyl	*cy;
	t_cy_func	f;

	cy = (t_obj_cyl *)obj;
	f.t_side = mrt_int_intersect_cy_side(ray, cy);
	if (f.t_side == FLT_MAX)
		f.t_min = FLT_MAX;
	else
	{
		f.hit_point = vec3_add(coord_to_vec3(ray->cam->pos),
				vec3_scale(ray->raycast, (float)f.t_side));
		f.cylinder_to_hit = vec3_sub(f.hit_point, coord_to_vec3(cy->base.pos));
		f.height_projection = vec3_dot(f.cylinder_to_hit, cy->axis);
		if (f.height_projection >= 0.0f && f.height_projection <= cy->h)
			f.t_min = f.t_side;
		else
			f.t_min = FLT_MAX;
	}
	f.t_top = mrt_int_intersect_cy_cap(ray, cy, 1);
	f.t_bottom = mrt_int_intersect_cy_cap(ray, cy, 0);
	if (f.t_top != FLT_MAX && (f.t_min == FLT_MAX || f.t_top < f.t_min))
		f.t_min = f.t_top;
	if (f.t_bottom != FLT_MAX && (f.t_min == FLT_MAX || f.t_bottom < f.t_min))
		f.t_min = f.t_bottom;
	return (f.t_min);
}
