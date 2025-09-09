/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_int_ray_focal_from_fov.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 16:56:19 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/09/06 16:56:20 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_render.h"

float	mrt_int_ray_focal_from_fov(int fov)
{
	float		tan_val;

	if (fov <= 0)
		return (FOCAL_LENGTH_MAX);
	if (180 <= fov)
		return (FLT_EPSILON);
	tan_val = tanf((float)fov * M_PI / 360.0f);
	return (1.0f / tan_val);
}
