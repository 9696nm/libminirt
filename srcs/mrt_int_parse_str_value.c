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

int	mrt_int_parse_str_bright(const char *str, void *ptr)
{
	float	fl;

	if (str == NULL || ptr == NULL)
		return (false);
	fl = lite_atof(str);
	if (fl == NAN || fl < 0.0f || 1.0f < fl)
		return (false);
	*(unsigned char *)ptr = (unsigned char)(fl * 255.0f + 0.5f);
	return (true);
}

int	mrt_int_parse_str_ufloat(const char *str, void *ptr)
{
	float	fl;

	if (str == NULL || ptr == NULL)
		return (false);
	fl = lite_atof(str);
	if (fl == NAN || fl < 0.0f)
		return (false);
	*(float *)ptr = fl;
	return (true);
}

int	mrt_int_parse_str_fov(const char *str, void *ptr)
{
	int	fov;

	if (str == NULL || ptr == NULL)
		return (false);
	fov = ft_atoi(str);
	if (fov < 0 || 180 < fov)
		return (false);
	*(int *)ptr = fov;
	return (true);
}
