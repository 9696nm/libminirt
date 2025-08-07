/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_int_obj_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:02:36 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/08/07 13:02:37 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_int.h"

int	handle_c(t_scene *vars, char *str __attribute__((unused)))
{
	t_cam_obj	*new;

	new = malloc(sizeof(t_cam_obj));
	if (new == NULL)
		return (false);
	vars->objects[vars->num_obj] = (t_obj_base *)new;
	vars->num_obj++;
	return (true);
}

int	handle_pl(t_scene *vars, char *str __attribute__((unused)))
{
	t_pln_obj	*new;

	new = malloc(sizeof(t_pln_obj));
	if (new == NULL)
		return (false);
	vars->objects[vars->num_obj] = (t_obj_base *)new;
	vars->num_obj++;
	return (true);
}

int	handle_sp(t_scene *vars, char *str __attribute__((unused)))
{
	t_sph_obj	*new;

	new = malloc(sizeof(t_sph_obj));
	if (new == NULL)
		return (false);
	vars->objects[vars->num_obj] = (t_obj_base *)new;
	vars->num_obj++;
	return (true);
}

int	handle_cy(t_scene *vars, char *str __attribute__((unused)))
{
	t_cyl_obj	*new;

	new = malloc(sizeof(t_cyl_obj));
	if (new == NULL)
		return (false);
	vars->objects[vars->num_obj] = (t_obj_base *)new;
	vars->num_obj++;
	return (true);
}
