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
