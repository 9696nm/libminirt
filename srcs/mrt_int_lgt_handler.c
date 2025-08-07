/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_int_lgt_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:02:43 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/08/07 13:02:44 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_int.h"

int	handle_a(t_scene *vars, char *str __attribute__((unused)))
{
	t_amb_lgt	*new;

	new = malloc(sizeof(t_amb_lgt));
	if (new == NULL)
		return (false);
	vars->lights[vars->num_lgt] = (t_lgt_base *)new;
	vars->num_lgt++;
	return (true);
}

int	handle_l(t_scene *vars, char *str __attribute__((unused)))
{
	t_amb_lgt	*new;

	new = malloc(sizeof(t_amb_lgt));
	if (new == NULL)
		return (false);
	vars->lights[vars->num_lgt] = (t_lgt_base *)new;
	vars->num_lgt++;
	return (true);
}

int	handle_default(t_scene *vars __attribute__((unused)),
	char *str __attribute__((unused)))
{
	return (true);
}
