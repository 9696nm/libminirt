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

/**
 * 色成分を0-255の範囲でクランプする
 */
static unsigned char	clamp_color(float value)
{
	if (value < 0.0f)
		return (0);
	if (value > 255.0f)
		return (255);
	return ((unsigned char)value);
}

static int	is_in_shadow(t_scene *scene, t_vec3 hit_point, t_vec3 light_dir, 
					t_vec3 normal)
{
	t_base_cam		cam;
	t_ray			shadow_ray;
	unsigned int	i;
	float			t;
	const float		shadow_bias = 0.0015f;

	shadow_ray.cam = &cam;
	shadow_ray.cam->pos = vec3_to_coord(
		vec3_add(hit_point, vec3_scale(normal, shadow_bias)));
	shadow_ray.raycast = light_dir;
	shadow_ray.colision = NULL;
	shadow_ray.distance = FLT_MAX;
	i = 0;
	while (i < scene->num_obj)
	{
		t = scene->objects[i]->intersect(&shadow_ray, scene->objects[i]);
		if (t > FLT_EPSILON && t < (vec3_length(light_dir) - shadow_bias))
			return (false);
		i++;
	}
	return (true);
}

/**
 * 点光源からの拡散反射の計算
 */
static unsigned int	calculate_point_light(t_scene *scene, t_ray *ray, t_vec3 normal)
{
	unsigned int	i;
	t_lgt_pt		*point_light;
	t_vec3			hit_point;
	t_vec3			light_dir;
	float			light_distance;
	float			cos_angle;
	float			brightness;
	unsigned char	obj_r, obj_g, obj_b;
	unsigned char	light_r, light_g, light_b;
	float			diffuse_r, diffuse_g, diffuse_b;
	float			total_r, total_g, total_b;

	hit_point = vec3_add(coord_to_vec3(ray->cam->pos),
		vec3_scale(ray->raycast, ray->distance));
	
	total_r = 0.0f;
	total_g = 0.0f;
	total_b = 0.0f;
	
	obj_r = (ray->colision->col.value >> 16) & 0xFF;
	obj_g = (ray->colision->col.value >> 8) & 0xFF;
	obj_b = ray->colision->col.value & 0xFF;
	
	// 全ての点光源を処理
	i = 0;
	while (i < scene->num_lgt)
	{
		if (scene->lights[i]->type == LGT_POINT)
		{
			point_light = (t_lgt_pt *)scene->lights[i];
			
			// ライト方向と距離を計算
			light_dir = vec3_sub(coord_to_vec3(point_light->pos), hit_point);
			light_distance = vec3_length(light_dir);
			light_dir = vec3_normalize(light_dir);
			
			// シャドウチェック
			if (is_in_shadow(scene, hit_point, light_dir, normal) == true)
			{
				// 拡散反射の計算（Lambert's cosine law）
				cos_angle = vec3_dot(normal, light_dir);
				if (cos_angle > 0.0f)
				{
					brightness = (float)point_light->base.bright / 255.0f;
					
					light_r = (point_light->base.col.value >> 16) & 0xFF;
					light_g = (point_light->base.col.value >> 8) & 0xFF;
					light_b = point_light->base.col.value & 0xFF;
					
					// 距離による減衰（調整済み減衰モデル）
					float attenuation = 1.0f / (0.2f + 0.02f * light_distance + 0.001f * light_distance * light_distance);
					
					// 最小減衰値を設定
					if (attenuation < 0.1f)
						attenuation = 0.1f;
					
					diffuse_r = (float)obj_r * (float)light_r * cos_angle * brightness * attenuation / 255.0f;
					diffuse_g = (float)obj_g * (float)light_g * cos_angle * brightness * attenuation / 255.0f;
					diffuse_b = (float)obj_b * (float)light_b * cos_angle * brightness * attenuation / 255.0f;
					
					total_r += diffuse_r;
					total_g += diffuse_g;
					total_b += diffuse_b;
				}
			}
		}
		i++;
	}
	
	return ((clamp_color(total_r) << 16) |
			(clamp_color(total_g) << 8) |
			clamp_color(total_b));
}

/**
 * 総合的な光源計算
 */
unsigned int	mrt_int_calculate_lighting(t_scene *scene, t_ray *ray)
{
	t_vec3			normal;
	unsigned int	ambient_color;
	unsigned int	diffuse_color;
	unsigned char	amb_r, amb_g, amb_b;
	unsigned char	dif_r, dif_g, dif_b;
	float			final_r, final_g, final_b;

	if (ray->colision == NULL)
		return (0u);
	normal = ray->colision->normal(ray, ray->colision);
	ambient_color = mrt_int_calculate_ambient_light(scene, ray->colision->col.value);
	
	// 点光源からの拡散反射を計算
	diffuse_color = calculate_point_light(scene, ray, normal);
	
	// 環境光と拡散反射を合成
	amb_r = (ambient_color >> 16) & 0xFF;
	amb_g = (ambient_color >> 8) & 0xFF;
	amb_b = ambient_color & 0xFF;
	
	dif_r = (diffuse_color >> 16) & 0xFF;
	dif_g = (diffuse_color >> 8) & 0xFF;
	dif_b = diffuse_color & 0xFF;
	
	final_r = (float)amb_r + (float)dif_r;
	final_g = (float)amb_g + (float)dif_g;
	final_b = (float)amb_b + (float)dif_b;
	
	return ((clamp_color(final_r) << 16) |
			(clamp_color(final_g) << 8) |
			clamp_color(final_b));
}
