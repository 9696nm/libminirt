/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:55:19 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/08/26 14:51:57 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_int.h"

t_scene	*mrt_init(void)
{
	t_scene	*scene;

	scene = malloc(sizeof(t_scene));
	if (scene == NULL)
		return (NULL);
	scene->pfx_used_bits = 0b0;
	scene->num_cam = 0;
	scene->num_lgt = 0;
	scene->num_obj = 0;
	return (scene);
}
