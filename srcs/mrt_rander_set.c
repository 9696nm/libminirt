/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_rander_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:55:19 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/08/26 15:28:29 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_int.h"

#include <time.h>

static void	mlx_pixel_set(t_img_info *info, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || info->width <= x || y < 0 || info->height <= y)
		return ;
	dst = info->addr + (y * info->size_line + x * (info->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	len = 0;

int	mrt_rander_set(t_scene *scene, void *img, int width, int height)
{
	t_img_info	info;

	info.addr = mlx_get_data_addr(img, &info.bits_per_pixel, &info.size_line,
			&info.endian);
	info.width = width;
	info.height = height;
	if (len % 2)
		for (int x=0; x<100; x++)
			for (int y=0; y<100; y++)
				mlx_pixel_set(&info, width-x, height-y, 0x87cefa);
	else
		for (int x=50; x<150; x++)
			for (int y=50; y<150; y++)
				mlx_pixel_set(&info, width-x, height-y, 0xffb6c1);
	len++;
	return (0);
}
