/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_int_parse_handle_lgt.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:02:43 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/08/26 14:51:57 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_int.h"
#include "utils_parse.h"

int	mrt_int_parse_handle_a(t_scene *scene, const char *str)
{
	t_lgt_amb		stk;
	t_lgt_amb		*new;
	const t_fp_maps	map[] = {
	{mrt_int_parse_str_bright, &stk.base.bright},
	{mrt_int_parse_str_color, &stk.base.col},
	{NULL, NULL}};

	stk.base.type = LGT_AMBIENT;
	if (mrt_int_parse_str_split(str + ft_strlen("A"), map) == false)
		return (false);
	new = malloc(sizeof(t_lgt_amb));
	if (new == NULL)
		return (false);
	ft_memcpy(new, &stk, sizeof(t_lgt_amb));
	scene->lights[scene->num_lgt] = (t_base_lgt *)new;
	scene->num_lgt++;
	return (true);
}

int	mrt_int_parse_handle_l(t_scene *scene, const char *str)
{
	t_lgt_pt		stk;
	t_lgt_pt		*new;
	const t_fp_maps	map[] = {
	{mrt_int_parse_str_coord, &stk.pos},
	{mrt_int_parse_str_bright, &stk.base.bright},
	{mrt_int_parse_str_color, &stk.base.col},
	{NULL, NULL}};

	stk.base.type = LGT_POINT;
	if (mrt_int_parse_str_split(str + ft_strlen("L"), map) == false)
		return (false);
	new = malloc(sizeof(t_lgt_pt));
	if (new == NULL)
		return (false);
	ft_memcpy(new, &stk, sizeof(t_lgt_pt));
	scene->lights[scene->num_lgt] = (t_base_lgt *)new;
	scene->num_lgt++;
	return (true);
}
