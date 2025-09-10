/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_int_lighting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 10:00:00 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/01/17 10:00:00 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_int.h"
#include "utils_render.h"

unsigned int	mrt_int_calculate_ambient_light(t_scene *scene,
		unsigned int obj_col)
{
	t_argb			res_col;
	t_argb			amb_col;
	unsigned char	amb_inten;
	unsigned int	index;

	amb_inten = 0;
	amb_col.value = 0xFFFFFFFF;
	index = 0;
	while (index < scene->num_lgt)
	{
		if (scene->lights[index]->type == LGT_AMBIENT)
		{
			amb_inten = scene->lights[index]->bright;
			amb_col.value = scene->lights[index]->col.value;
		}
		index++;
	}
	res_col.value = obj_col;
	res_col.s_c.r = ((int)res_col.s_c.r * amb_col.s_c.r * amb_inten) >> 16;
	res_col.s_c.g = ((int)res_col.s_c.g * amb_col.s_c.g * amb_inten) >> 16;
	res_col.s_c.b = ((int)res_col.s_c.b * amb_col.s_c.b * amb_inten) >> 16;
	return (res_col.value);
}

int	mrt_int_is_in_shadow(t_scene *scene, t_vec3 normal, t_dif_cal v)
{
	t_base_cam		cam;
	t_ray			shadow_ray;
	unsigned int	i;
	float			t;
	const float		shadow_bias = 0.0015f;

	shadow_ray.cam = &cam;
	shadow_ray.cam->pos = vec3_to_coord(
			vec3_add(v.hit_point, vec3_scale(normal, shadow_bias)));
	shadow_ray.raycast = v.light_dir;
	shadow_ray.colision = NULL;
	shadow_ray.distance = FLT_MAX;
	i = 0;
	while (i < scene->num_obj)
	{
		t = scene->objects[i]->intersect(&shadow_ray, scene->objects[i]);
		if (t > FLT_EPSILON && t < (v.dist - shadow_bias))
			return (true);
		i++;
	}
	return (false);
}

static unsigned int	calculate_point_light(t_scene *scene,
		t_ray *ray, t_vec3 normal)
{
	unsigned int	i;
	t_argb			buf;
	t_argb			total;

	total.value = 0x0;
	i = 0;
	while (i < scene->num_lgt)
	{
		if (scene->lights[i]->diffuse)
		{
			buf.value = scene->lights[i]->diffuse
				(scene, ray, scene->lights[i], normal);
			total.s_c.r += buf.s_c.r;
			total.s_c.g += buf.s_c.g;
			total.s_c.b += buf.s_c.b;
		}
		i++;
	}
	return (total.value);
}

static unsigned char	clamp_color(int value)
{
	if (value < 0.)
		return (0);
	if (value > 255)
		return (255);
	return ((unsigned char)value);
}

unsigned int	mrt_int_calculate_lighting(t_scene *scene, t_ray *ray)
{
	t_vec3	normal;
	t_argb	amb_col;
	t_argb	dif_col;
	t_argb	res_col;

	if (ray->colision == NULL)
		return (0u);
	normal = ray->colision->normal(ray, ray->colision);
	amb_col.value = mrt_int_calculate_ambient_light
		(scene, ray->colision->col.value);
	dif_col.value = calculate_point_light(scene, ray, normal);
	res_col.s_c.r = clamp_color((int)amb_col.s_c.r + dif_col.s_c.r);
	res_col.s_c.g = clamp_color((int)amb_col.s_c.g + dif_col.s_c.g);
	res_col.s_c.b = clamp_color((int)amb_col.s_c.b + dif_col.s_c.b);
	return (res_col.value);
}
