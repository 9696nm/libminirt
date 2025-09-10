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

static t_argb	color_convert(t_argb c1, t_argb c2, float bias)
{
	t_argb	res;

	res.s_c.r = (((int)c1.s_c.r * c2.s_c.r) << 8) * bias;
	res.s_c.g = (((int)c1.s_c.g * c2.s_c.g) << 8) * bias;
	res.s_c.b = (((int)c1.s_c.b * c2.s_c.b) << 8) * bias;
	return (res);
}

t_argb	mrt_int_ray_light_diffuse_pt(t_scene scene, const t_ray *ray,
		void *lgt, t_vec3 normal)
{
	t_argb		col;
	float		attn;
	float		dist;
	float		cos_angle;
	t_vec3		hit_point;
	t_lgt_pt	*pt;

	pt = (t_lgt_pt *)lgt;
	hit_point = vec3_add(coord_to_vec3(ray->cam->pos),
	vec3_scale(ray->raycast, ray->distance));
	light_dir = vec3_sub(coord_to_vec3(point_light->pos), hit_point);
	dist = vec3_length(light_dir);
	light_dir = vec3_normalize(light_dir);
	
	// シャドウチェック
	if (is_in_shadow(scene, hit_point, light_dir, dist, normal))
	{
		cos_angle = vec3_dot(normal, light_dir);
		if (0.0f < cos_angle)
		{
			attn = 1.0f / (0.2f + 0.02f * dist + 0.001f * dist * dist);
			if (attn < 0.1f)
				attn = 0.1f;
			col = color_convert(ray->colision->col, pt->base.col,
					(float)pt->base.bright * cos_angle * attn / 255.0f);
		}
	}
	return (col);
}
