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

#include "minirt_int.h"

static bool	has_extension(const char *path, const char *ext)
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

static int	extract_valid_prefix(const char *buf, t_scene *vars,
	const t_pfx_hdl *handlers)
{
	unsigned int	match_idx;

	match_idx = 0;
	while (handlers[match_idx].pfx)
	{
		if (ft_strncmp(buf, handlers[match_idx].pfx, 1) == 0)
		{
			if (ft_isupper(*buf) && vars->pfx_used_bits & (1U << match_idx))
				return (ret_errmsg(-1, ERR_MULTIPLE_UNIQUE_PREFIXES));
			vars->pfx_used_bits |= (1U << match_idx);
			return ((int)match_idx);
		}
		match_idx++;
	}
	if (*buf == '\n')
		return ((int)match_idx);
	return (ret_errmsg(-1, ERR_NO_MATCHING_PREFIX));
}

int	mrt_int_set_array(t_scene *vars, int fd, const t_pfx_hdl *handlers)
{
	int		pfx_type;
	int		scene_cnt;
	char	*buf;

	scene_cnt = -1;
	buf = get_next_line(fd);
	if (buf == NULL)
		return (0);
	pfx_type = extract_valid_prefix(buf, vars, handlers);
	if (-1 < pfx_type)
	{
		if (handlers[(unsigned int)pfx_type].hdl(vars, buf))
			scene_cnt = mrt_int_set_array(vars, fd, handlers);
		else
			perror("handler");
		if (-1 < scene_cnt)
			scene_cnt++;
	}
	free(buf);
	return (scene_cnt);
}

int	mrt_set_value(t_scene *vars, char *path)
{
	int				fd;
	int				scene_cnt;
	const t_pfx_hdl	handlers[] = {
	{"A", handle_a},
	{"C", handle_c},
	{"L", handle_l},
	{"pl", handle_pl},
	{"sp", handle_sp},
	{"cy", handle_cy},
	{NULL, handle_default} /* feedback */
	};

	scene_cnt = 0;
	if (has_extension(path, RT_FILE_EXTENSION) == false)
		return (ret_errmsg(-1, ERR_INVALID_EXTENSION));
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (perrturn(-1, path));
	scene_cnt = mrt_int_set_array(vars, fd, handlers);
	close(fd);
	return (scene_cnt);
}
