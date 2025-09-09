/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_select_cam_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 17:32:56 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/09/05 17:32:57 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_int.h"

t_base_cam	*mrt_int_get_cam_type(t_scene *scene)
{
	unsigned int	cam_id;

	cam_id = 0;
	while (cam_id < scene->num_cam)
	{
		if (scene->cameras[cam_id]->type == scene->cam_type)
			return (scene->cameras[cam_id]);
		cam_id++;
	}
	return (NULL);
}
