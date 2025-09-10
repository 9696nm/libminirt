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
#include "utils_mlx.h"
#include "utils_render.h"

void	mrt_int_pixel_set_mlx(t_img_info *info,
			int x, int y, unsigned int color)
{
	char	*dst;

	if (x < 0 || y < 0)
		return ;
	dst = info->addr + (y * info->size_line + x * (info->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	mrt_image_render_mlx(t_scene *scene, void *img, int width, int height)
{
	t_img_info	info;
	int			x;
	int			y;

	info.addr = mlx_get_data_addr(img, &info.bits_per_pixel, &info.size_line,
			&info.endian);
	scene->aspect_ratio = (float)width / height;
	scene->ndc_norm.x = 2.0f / width;
	scene->ndc_norm.y = 2.0f / height;
	y = height;
	while (0 < y--)
	{
		x = width;
		while (0 < x--)
			mrt_int_pixel_set_mlx(&info, x, y,
				mrt_int_pixel_color(scene, x, y));
	}
	return (0);
}

// int	len = 0;

	// if (len % 2)
	// 	for (int x=0; x<1; x++)
	// 		for (int y=0; y<1; y++)
	// 			mrt_int_pixel_set_mlx(&info, width-x, height-y, 0x87cefa);
	// else
	// 	for (int x=1; x<2; x++)
	// 		for (int y=1; y<2; y++)
	// 			mrt_int_pixel_set_mlx(&info, width-x, height-y, 0xffb6c1);
	// len++;
