/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_int_parse_struct.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:31:48 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/08/21 17:31:50 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_int.h"

// int	mrt_int_parse_color(const char *str, void *ptr)
// {
// 	int				comma;
// 	int				value;
// 	unsigned int	color;

// 	if (str == NULL)
// 		return (false);
// 	comma = 2;
// 	color = 0;
// 	while (*str)
// 	{
// 		value = atoi(str);
// 		if (value < 0l || 255l < value)
// 			return (false);
// 		color = (color << 8) | (unsigned char)value;
// 		if (comma-- == 0)
			
// 		str = tmp;
// 	}
// 	return (true);
// }

const char	*mrt_int_parse_coord(t_coord3 *ptr, const char *str)
{
	;
}

const char	*mrt_int_parse_vecter3(t_vec3 *ptr, const char *str)
{
	;
}
