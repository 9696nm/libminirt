/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:12:40 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/08/07 14:13:14 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_MLX_H
# define UTILS_MLX_H

# include "mlx.h"

typedef struct s_image_info
{
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_img_info;

void	mrt_int_pixel_set_mlx(t_img_info *info,
			int x, int y, unsigned int color);

#endif /* UTILS_MLX_H */
