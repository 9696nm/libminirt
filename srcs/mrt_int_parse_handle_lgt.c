/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_int_parse_handle_lgt.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:02:43 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/08/21 17:09:52 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_int.h"

int	mrt_int_parse_handle_a(t_scene *vars, const char *str)
{
	t_lgt_amb	stk;
	t_lgt_amb	*new;
	t_fp_maps	map[] = {
	{mrt_int_parse_bright, &stk.base.bright}, {NULL, NULL}};

	stk.base.type = LGT_AMBIENT;
	if (mrt_int_parse_str_split(str + ft_strlen("A"), map) == false)
		return (false);
	new = malloc(sizeof(t_lgt_amb));
	if (new == NULL)
		return (false);
	ft_memcpy(new, &stk, sizeof(t_lgt_amb));
	vars->lights[vars->num_lgt] = (t_base_lgt *)new;
	vars->num_lgt++;
	return (true);
}

int	mrt_int_parse_handle_l(t_scene *vars, const char *str)
{
	t_lgt_amb	*new;

	new = malloc(sizeof(t_lgt_amb));
	if (new == NULL)
		return (false);
	vars->lights[vars->num_lgt] = (t_base_lgt *)new;
	vars->num_lgt++;
	return (true);
}
