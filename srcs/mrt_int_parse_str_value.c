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

const char	*mrt_int_parse_float(float *ptr, const char *str)
{
	;
}

unsigned char	mrt_int_parse_bright(const char *str, char **endptr)
{
	char	*tmp;
	float	bright;

	if (endptr)
		*endptr = NULL;
	if (str == NULL)
		return (0);
	while (ft_isspace(*str))
		str++;
	bright = strtof(str, &tmp);
	if (bright == NAN || bright < 0.0f || 1.0f < bright)
		return (0);
	if (endptr)
		*endptr = tmp;
	return ((unsigned char)(bright * 255.0f + 0.5f));
}
