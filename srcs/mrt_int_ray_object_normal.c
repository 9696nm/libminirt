/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_int_ray_object_normal.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 16:56:19 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/09/06 16:56:20 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_int.h"
#include "utils_render.h"

t_vec3	mrt_int_ray_object_normal_sp(const t_ray *ray, void *obj)
{
	t_obj_sph	*sph;
	t_vec3		normal;
	t_vec3		hit_point;

	sph = (t_obj_sph *)obj;
	hit_point = vec3_add(coord_to_vec3(ray->cam->pos),
			vec3_scale(ray->raycast, ray->distance));
	normal = vec3_sub(hit_point, coord_to_vec3(sph->base.pos));
	normal = vec3_normalize(normal);
	return (normal);
}

t_vec3	mrt_int_ray_object_normal_pl(const t_ray *ray, void *obj)
{
	t_obj_pln	*pln;
	t_vec3		normal;

	pln = (t_obj_pln *)obj;
	normal = pln->normal;
	if (vec3_dot(normal, ray->raycast) > 0.0f)
		normal = vec3_scale(normal, -1.0f);
	return (normal);
}

t_vec3	mrt_int_ray_object_normal_cy(const t_ray *ray, void *obj)
{
	t_obj_cyl	*cyl;
	float		h_proj;
	t_vec3		hit_point;
	const float	cap_margin = 0.01f;
	t_vec3		normal;

	cyl = (t_obj_cyl *)obj;
	hit_point = vec3_add(coord_to_vec3(ray->cam->pos),
			vec3_scale(ray->raycast, ray->distance));
	h_proj = vec3_dot(vec3_sub(hit_point, coord_to_vec3(cyl->base.pos)),
			cyl->axis);
	if (h_proj <= cap_margin)
		normal = vec3_scale(cyl->axis, -1.0f);
	else if (h_proj >= (cyl->h - cap_margin))
		normal = cyl->axis;
	else
	{
		normal = vec3_sub(hit_point, vec3_add(coord_to_vec3(cyl->base.pos),
					vec3_scale(cyl->axis, h_proj)));
		normal = vec3_normalize(normal);
	}
	return (normal);
}
