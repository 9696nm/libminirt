/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_int_parse_handle_obj.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:02:36 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/08/26 14:51:57 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_int.h"
#include "utils_parse.h"

int	mrt_int_parse_handle_pl(t_scene *scene, const char *str)
{
	t_obj_pln		stk;
	t_obj_pln		*new;
	const t_fp_maps	map[] = {
	{mrt_int_parse_str_coord, &stk.base.pos},
	{mrt_int_parse_str_vecter3, &stk.normal},
	{mrt_int_parse_str_color, &stk.base.col},
	{NULL, NULL}};

	stk.base.type = OBJ_PLANE;
	if (mrt_int_parse_str_split(str + ft_strlen("pl"), map) == false)
		return (false);
	new = malloc(sizeof(t_obj_pln));
	if (new == NULL)
		return (false);
	ft_memcpy(new, &stk, sizeof(t_obj_pln));
	scene->objects[scene->num_obj] = (t_base_obj *)new;
	scene->num_obj++;
	return (true);
}

int	mrt_int_parse_handle_sp(t_scene *scene, const char *str)
{
	t_obj_sph		stk;
	t_obj_sph		*new;
	const t_fp_maps	map[] = {
	{mrt_int_parse_str_coord, &stk.base.pos},
	{mrt_int_parse_str_ufloat, &stk.d},
	{mrt_int_parse_str_color, &stk.base.col},
	{NULL, NULL}};

	stk.base.type = OBJ_SPHERE;
	if (mrt_int_parse_str_split(str + ft_strlen("sp"), map) == false)
		return (false);
	new = malloc(sizeof(t_obj_sph));
	if (new == NULL)
		return (false);
	ft_memcpy(new, &stk, sizeof(t_obj_sph));
	scene->objects[scene->num_obj] = (t_base_obj *)new;
	scene->num_obj++;
	return (true);
}

int	mrt_int_parse_handle_cy(t_scene *scene, const char *str)
{
	t_obj_cyl		stk;
	t_obj_cyl		*new;
	const t_fp_maps	map[] = {
	{mrt_int_parse_str_coord, &stk.base.pos},
	{mrt_int_parse_str_vecter3, &stk.axis},
	{mrt_int_parse_str_ufloat, &stk.d},
	{mrt_int_parse_str_ufloat, &stk.h},
	{mrt_int_parse_str_color, &stk.base.col},
	{NULL, NULL}};

	stk.base.type = OBJ_CYLINDER;
	if (mrt_int_parse_str_split(str + ft_strlen("sy"), map) == false)
		return (false);
	new = malloc(sizeof(t_obj_cyl));
	if (new == NULL)
		return (false);
	ft_memcpy(new, &stk, sizeof(t_obj_cyl));
	scene->objects[scene->num_obj] = (t_base_obj *)new;
	scene->num_obj++;
	return (true);
}
