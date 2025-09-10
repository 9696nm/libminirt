/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_int_pixel_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 17:32:56 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/09/05 17:32:57 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_int.h"
#include "utils_render.h"

unsigned int	mrt_int_pixel_color(t_scene *scene, int x, int y)
{
	t_ray	ray;

	if (mrt_int_pixel_raycast(scene, &ray, x, y) == false)
		return (0u);
	if (mrt_int_intersect_search(scene, &ray) == false)
		return (0u);
	return (mrt_int_calculate_lighting(scene, &ray));
}
