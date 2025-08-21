/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_int_parse_handle_cam.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:02:43 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/08/18 01:56:26 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_int.h"

int	mrt_int_parse_handle_c(t_scene *vars, const char *str)
{
	t_cam_persp	*new;

	new = malloc(sizeof(t_cam_persp));
	if (new == NULL)
		return (false);
	vars->cameras[vars->num_cam] = (t_base_cam *)new;
	vars->num_cam++;
	return (true);
}

int	mrt_int_parse_handle_default(t_scene *vars __attribute__((unused)),
	const char *str __attribute__((unused)))
{
	return (true);
}
