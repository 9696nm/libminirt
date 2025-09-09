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

int	mrt_int_pixel_raycast(t_vec3 *raycast, t_scene *scene, int x, int y)
{
	t_ndc			ndc;
	t_base_cam		*cam;
	const t_trance	trances[] = {
		mrt_int_pixel_raycast_perspective};

	cam = mrt_int_get_cam_type(scene);
	if (cam == NULL)
		return (false);
	ndc.x = scene->ndc_norm.x * x - 1.0f;
	ndc.y = 1.0f - scene->ndc_norm.y * y;
	*raycast = trances[scene->cam_type]
		(cam, ndc, scene->aspect_ratio);
	return (true);
}

t_vec3	mrt_int_pixel_raycast_perspective(t_base_cam *cam,
					t_ndc ndc, float aspect)
{
	t_vec3		ray;
	t_quat		ray_world;
	t_cam_persp	*persp;

	persp = (t_cam_persp *)cam;
	ray.x = ndc.x * aspect;
	ray.y = ndc.y;
	ray.z = persp->focal_length;
	if (ray.z < FOCAL_LENGTH_MAX)
		ray = vec3_normalize(ray);
	else
		ray = (t_vec3){0.0f, 0.0f, 1.0f};
	ray_world = quat_rotate((t_quat){ray.x, ray.y, ray.z, 0}, persp->cam_rot);
	printf("wor-> x:%f y:%f z:%f w:%f\n", ray_world.x, ray_world.y, ray_world.z, ray_world.w);
	return ((t_vec3){ray_world.x, ray_world.y, ray_world.z});
}
