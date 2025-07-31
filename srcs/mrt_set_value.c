/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_set_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:55:17 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/07/08 18:55:18 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "string.h"
#include "ft/string.h"
#include "minirt_int.h"

const t_prefix_handler g_handlers[] = {
	{"A", handle_A},
	{"C", handle_C},
	{"L", handle_L},
	{"pl", handle_pl},
	{"sp", handle_sp},
	{"cy", handle_cy},
	{NULL, handle_default} /* feedback */
};

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

// void	dispatch_prefix(const char *input) {
// 	int	i = 0;

// 	while (g_handlers[i].prefix != NULL) {
// 		if (strcmp(g_handlers[i].prefix, input) == 0) {
// 			g_handlers[i].handler();
// 			return;
// 		}
// 		i++;
// 	}
// 	/* 対応なし → default handler */
// 	g_handlers[i].handler();
// }

int	check_prefix()
{

}

int		mrt_set_value(t_scene *vars, char *path)
{
	int	fd;
	int	index;

	index = 0;
	if (has_extension(path, RT_FILE_EXTENSION) == false)
		return (ret_errmsg(-1, ERR_INVALID_EXTENSION));
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (perrturn(-1, path));
	(void)vars;
	close(fd);
	return (index);
}
