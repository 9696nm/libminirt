/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_int_obj_init_handler.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:02:36 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/08/11 12:28:16 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_int.h"

int	mrt_int_parse_handle_pl(t_scene *vars, const char *str)
{
	t_obj_pln	*new;

	new = malloc(sizeof(t_obj_pln));
	if (new == NULL)
		return (false);
	vars->objects[vars->num_obj] = (t_base_obj *)new;
	vars->num_obj++;
	return (true);
}

int	mrt_int_parse_handle_sp(t_scene *vars, const char *str)
{
	t_obj_sph	*new;

	new = malloc(sizeof(t_obj_sph));
	if (new == NULL)
		return (false);
	vars->objects[vars->num_obj] = (t_base_obj *)new;
	vars->num_obj++;
	return (true);
}

int	mrt_int_parse_handle_cy(t_scene *vars, const char *str)
{
	t_obj_cyl	*new;

	new = malloc(sizeof(t_obj_cyl));
	if (new == NULL)
		return (false);
	vars->objects[vars->num_obj] = (t_base_obj *)new;
	vars->num_obj++;
	return (true);
}
