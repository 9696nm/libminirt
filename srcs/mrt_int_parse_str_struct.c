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

unsigned int	mrt_int_parse_color(const char *str, char **endptr)
{
	char			*tmp;
	long int		value;
	unsigned int	color;

	if (endptr)
		*endptr = NULL;
	if (str == NULL)
		return (0);
	while (ft_isspace(*str))
		str++;
	color = 0;
	while (*str)
	{
		value = strtol(str, &tmp, 10);
		if (value < 0l || 255l < value)
			return (0);
		str = tmp;
		color = (color << 8) | (unsigned char)value;
	}
	if (endptr)
		*endptr = tmp;
	return (color);
}

const char	*mrt_int_parse_coord(t_coord3 *ptr, const char *str)
{
	;
}

const char	*mrt_int_parse_vecter3(t_vec3 *ptr, const char *str)
{
	;
}
