/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:41:19 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/08/26 14:58:16 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_int.h"

void	mrt_destroty(t_scene *scene)
{
	if (scene == NULL)
		return ;
	while (scene->num_cam--)
		free(scene->cameras[scene->num_cam]);
	while (scene->num_lgt--)
		free(scene->lights[scene->num_lgt]);
	while (scene->num_obj--)
		free(scene->objects[scene->num_obj]);
	free(scene);
}
