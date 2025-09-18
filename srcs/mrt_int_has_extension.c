/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_read_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:55:17 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/08/26 15:09:59 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_int.h"

bool	has_extension(const char *path, const char *ext)
{
	const char	*filename;
	const char	*dot;

	if (path == NULL || ext == NULL)
		return (false);
	filename = ft_strrchr(path, '/');
	if (filename == NULL)
		filename = path;
	else
		filename++;
	dot = ft_strrchr(filename, '.');
	if (dot == NULL || ft_strcmp(filename, ext) == 0)
		return (false);
	return (ft_strcmp(dot, ext) == 0);
}
