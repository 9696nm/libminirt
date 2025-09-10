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

void	mrt_select_cam_type(t_scene *scene, unsigned int index)
{
	if (index < CAM_UNKNOWN)
		scene->cam_type = index;
	else
	{
		ft_putstr_fd(ERR_NO_MATCHING_CAMERA_INDEX, STDERR_FILENO);
		ft_putnbr_fd(index, STDERR_FILENO);
		ft_putstr_fd(" .\n", STDERR_FILENO);
	}
}
