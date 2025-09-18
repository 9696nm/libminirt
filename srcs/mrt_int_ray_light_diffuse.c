/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_int_ray_light_diffuse.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 16:56:19 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/09/06 16:56:20 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_int.h"
#include "utils_render.h"

static unsigned int	color_convert(const t_ray *ray, t_lgt_pt *pt,
				float attn, float cos_angle)
{
	float	bright;
	t_argb	res;

	bright = (float)pt->base.bright / 255.0f;
	res.s_c.r = (float)ray->colision->col.s_c.r * (float)pt->base.col.s_c.r
		* cos_angle * bright * attn / 255.0f;
	res.s_c.g = (float)ray->colision->col.s_c.g * (float)pt->base.col.s_c.g
		* cos_angle * bright * attn / 255.0f;
	res.s_c.b = (float)ray->colision->col.s_c.b * (float)pt->base.col.s_c.b
		* cos_angle * bright * attn / 255.0f;
	return (res.value);
}

unsigned int	mrt_int_ray_light_diffuse_pt(t_scene *scene, const t_ray *ray,
		void *lgt, t_vec3 normal)
{
	t_argb		col;
	float		attn;
	float		cos_angle;
	t_dif_cal	v;
	t_lgt_pt	*pt;

	pt = (t_lgt_pt *)lgt;
	v.hit_point = vec3_add(coord_to_vec3(ray->cam->pos),
			vec3_scale(ray->raycast, ray->distance));
	v.light_dir = vec3_sub(coord_to_vec3(pt->pos), v.hit_point);
	v.dist = vec3_length(v.light_dir);
	v.light_dir = vec3_normalize(v.light_dir);
	col.value = 0;
	if (mrt_int_is_in_shadow(scene, normal, v) == false)
	{
		cos_angle = vec3_dot(normal, v.light_dir);
		if (0.0f < cos_angle)
		{
			attn = 1.0f / (1.0f + 0.02f * v.dist + 0.0015f * v.dist * v.dist);
			if (attn < 0.1f)
				attn = 0.1f;
			col.value = color_convert(ray, pt, attn, cos_angle);
		}
	}
	return (col.value);
}
