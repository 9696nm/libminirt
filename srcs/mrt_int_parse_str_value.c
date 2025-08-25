/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_int_parse_value.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 01:56:14 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/08/18 01:56:15 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_int.h"

const char	*mrt_int_parse_uint(unsigned int *ptr, const char *str)
{
	;
}

// float	*mrt_int_parse_float(const char *str, char **endptr)
// {
// 	char	*tmp;
// 	float	fl;

// 	if (endptr)
// 		*endptr = NULL;
// 	if (str == NULL)
// 		return (0);
// 	while (ft_isspace(*str))
// 		str++;
// 	fl = strtof(str, &tmp);
// 	if (fl == NAN || fl < 0.0f || 1.0f < fl)
// 		return (0);
// 	if (endptr)
// 		*endptr = tmp;
// 	return ((unsigned char)(fl * 255.0f + 0.5f));
// }

int	mrt_int_parse_bright(const char *str, void *ptr)
{
	unsigned char	*bright;
	float			fl;

	if (str == NULL || ft_isdigit(*str) == 0)
		return (false);
	bright = ptr;
	fl = atof(str);
	if (fl == NAN || fl < 0.0f || 1.0f < fl)
		return (false);
	*bright = (unsigned char)(fl * 255.0f + 0.5f);
	return (true);
}
