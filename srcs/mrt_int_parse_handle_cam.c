/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_int_parse_handle_cam.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:02:43 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/08/26 14:51:57 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_int.h"
#include "utils_parse.h"
#include "utils_render.h"

int	mrt_int_parse_handle_c(t_scene *scene, const char *str)
{
	t_cam_persp		stk;
	t_cam_persp		*new;
	const t_fp_maps	map[] = {
	{mrt_int_parse_str_coord, &stk.base.pos},
	{mrt_int_parse_str_vecter3, &stk.base.view},
	{mrt_int_parse_str_fov, &stk.fov},
	{NULL, NULL}};

	stk.base.type = CAM_PERSPECTIVE;
	if (mrt_int_parse_str_split(str + ft_strlen("C"), map) == false)
		return (false);
	stk.focal_length = mrt_int_ray_focal_from_fov(stk.fov);
	stk.cam_rot = quat_from_to((t_vec3){0, 0, 1}, vec3_normalize(stk.base.view));
	new = malloc(sizeof(t_cam_persp));
	if (new == NULL)
		return (false);
	ft_memcpy(new, &stk, sizeof(t_cam_persp));
	scene->cameras[scene->num_cam] = (t_base_cam *)new;
	scene->num_cam++;
	return (true);
}

int	mrt_int_parse_handle_default(t_scene *scene __attribute__((unused)),
	const char *str __attribute__((unused)))
{
	return (true);
}
