/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_image_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:55:19 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/08/26 15:28:29 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_int.h"
#include "utils_mlx.h"

int	mrt_image_clear_mlx(void *img, int width, int height)
{
	t_img_info	info;

	info.addr = mlx_get_data_addr(img, &info.bits_per_pixel, &info.size_line,
			&info.endian);
	ft_bzero(info.addr, width * height * (info.bits_per_pixel / 8));
	return (0);
}
