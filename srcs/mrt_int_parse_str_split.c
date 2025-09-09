/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_int_parse_str_split.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 19:13:17 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/08/25 19:13:42 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_int.h"
#include "utils_parse.h"

int	mrt_int_parse_str_split(const char *src, const t_fp_maps *map)
{
	unsigned int	idx;

	if (src == NULL || map == NULL)
		return (false);
	idx = 0;
	while (map[idx].fnc)
	{
		while (ft_isspace(*src))
			src++;
		if (*src == '\0' || map[idx].fnc(src, map[idx].ptr) == false)
			return (false);
		while (*src && ft_isspace(*src) == 0)
			src++;
		idx++;
	}
	return (true);
}
