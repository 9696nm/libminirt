/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:41:19 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/07/26 13:41:23 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_int.h"

void	mrt_destroty(t_scene *vars)
{
	if (vars == NULL)
		return ;

	/* debug start */
	printf("# cam:%u\n", vars->num_cam);
	while (vars->num_cam--)
	{
		mrt_int_debug_print_cam(vars->cameras[vars->num_cam]);
		free(vars->cameras[vars->num_cam]);
	}
	printf("# lgt:%u\n", vars->num_lgt);
	while (vars->num_lgt--)
	{
		mrt_int_debug_print_lgt(vars->lights[vars->num_lgt]);
		free(vars->lights[vars->num_lgt]);
	}
	printf("# obj:%u\n", vars->num_obj);
	while (vars->num_obj--)
	{
		mrt_int_debug_print_obj(vars->objects[vars->num_obj]);
		free(vars->objects[vars->num_obj]);
	}
	/* debug end */
	
	// while (vars->num_cam--)
	// 	free(vars->cameras[vars->num_cam]);
	// while (vars->num_lgt--)
	// 	free(vars->lights[vars->num_lgt]);
	// while (vars->num_obj--)
	// 	free(vars->objects[vars->num_obj]);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);

	free(vars);
}
