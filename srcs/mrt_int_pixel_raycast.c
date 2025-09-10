/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_int_pixel_raycast.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 17:32:56 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/09/05 17:32:57 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_int.h"
#include "utils_render.h"

int	mrt_int_pixel_raycast(t_scene *scene, t_ray *ray, int x, int y)
{
	t_ndc			ndc;
	unsigned int	cam_id;
	const t_trance	trances[] = {
		mrt_int_pixel_raycast_perspective};

	cam_id = 0;
	while (cam_id < scene->num_cam)
	{
		if (scene->cameras[cam_id]->type == scene->cam_type)
			break ;
		cam_id++;
	}
	if (cam_id == scene->num_cam)
		return (false);
	ndc.x = scene->ndc_norm.x * x - 1.0f;
	ndc.y = 1.0f - scene->ndc_norm.y * y;
	ray->cam = scene->cameras[cam_id];
	ray->raycast = trances[scene->cam_type]
		(ray->cam, ndc, scene->aspect_ratio);
	return (true);
}

t_vec3	mrt_int_pixel_raycast_perspective(t_base_cam *cam,
					t_ndc ndc, float aspect)
{
	t_vec3		ray_ndc;
	t_quat		ray_world;
	t_cam_persp	*persp;

	persp = (t_cam_persp *)cam;
	ray_ndc.x = ndc.x * aspect;
	ray_ndc.y = ndc.y;
	ray_ndc.z = persp->focal_length;
	if (ray_ndc.z < FOCAL_LENGTH_MAX)
		ray_ndc = vec3_normalize(ray_ndc);
	else
		ray_ndc = (t_vec3){0.0f, 0.0f, 1.0f};
	ray_world = quat_rotate(
			(t_quat){ray_ndc.x, ray_ndc.y, ray_ndc.z, 0}, persp->cam_rot);
	return ((t_vec3){ray_world.x, ray_world.y, ray_world.z});
}
