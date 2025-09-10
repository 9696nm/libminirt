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

static size_t	next_comma(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] && ft_isspace(str[len]) == 0)
	{
		if (str[len++] == ',')
			break ;
	}
	return (len);
}

int	mrt_int_parse_str_color(const char *str, void *ptr)
{
	int				loop;
	int				i;
	unsigned int	color;

	if (str == NULL || ptr == NULL)
		return (false);
	loop = 3;
	color = 0;
	while (loop--)
	{
		i = ft_atoi(str);
		if (*str == '\0' || ft_isspace(*str)
			|| *str == ',' || i < 0l || 255l < i)
			return (false);
		color = (color << 8) | (unsigned char)i;
		str += next_comma(str);
	}
	*(unsigned int *)ptr = color;
	return (true);
}

int	mrt_int_parse_str_coord(const char *str, void *ptr)
{
	t_coord3	coord;

	if (str == NULL || ptr == NULL)
		return (false);
	coord.x = lite_atof(str);
	if (ft_isspace(*str) || *str == ',' || coord.x == NAN)
		return (false);
	str += next_comma(str);
	coord.y = lite_atof(str);
	if (ft_isspace(*str) || *str == ',' || coord.y == NAN)
		return (false);
	str += next_comma(str);
	coord.z = lite_atof(str);
	if (ft_isspace(*str) || *str == ',' || coord.z == NAN)
		return (false);
	*(t_coord3 *)ptr = coord;
	return (true);
}

int	mrt_int_parse_str_vecter3(const char *str, void *ptr)
{
	t_vec3	vec;

	if (str == NULL || ptr == NULL)
		return (false);
	vec.x = lite_atof(str);
	if (ft_isspace(*str) || *str == ',' || vec.x == NAN)
		return (false);
	str += next_comma(str);
	vec.y = lite_atof(str);
	if (ft_isspace(*str) || *str == ',' || vec.y == NAN)
		return (false);
	str += next_comma(str);
	vec.z = lite_atof(str);
	if (ft_isspace(*str) || *str == ',' || vec.z == NAN)
		return (false);
	vec = vec3_normalize(vec);
	*(t_vec3 *)ptr = vec;
	return (true);
}
