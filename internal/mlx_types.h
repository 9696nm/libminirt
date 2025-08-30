/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_types.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:12:40 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/08/07 14:13:14 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_TYPES_H
# define MLX_TYPES_H

# include "mlx.h"

typedef struct s_image_info
{
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;

	int		width;
	int		height;
}	t_img_info;

#endif /* MLX_TYPES_H */
