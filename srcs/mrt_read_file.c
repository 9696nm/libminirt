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
#include "utils_parse.h"

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

static int	mrt_int_extract_valid_prefix(const char *buf, t_scene *scene,
	const t_pfx_hdl *handlers)
{
	unsigned int	match_idx;

	match_idx = 0;
	while (handlers[match_idx].pfx)
	{
		if (ft_strncmp(buf, handlers[match_idx].pfx, 1) == 0)
		{
			if (ft_isupper(*buf) && scene->pfx_used_bits & (1U << match_idx))
				return (ret_errmsg(-1, ERR_MULTIPLE_UNIQUE_PREFIXES));
			scene->pfx_used_bits |= (1U << match_idx);
			return ((int)match_idx);
		}
		match_idx++;
	}
	if (*buf == '\n')
		return ((int)match_idx);
	return (ret_errmsg(-1, ERR_NO_MATCHING_PREFIX));
}

static void	puterr_str(char *errmsg, char *arg)
{
	ft_putstr_fd(errmsg, STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putstr_fd("\".\n", STDERR_FILENO);
}

int	mrt_int_set_array(t_scene *scene, int fd, const t_pfx_hdl *handlers)
{
	int		pfx_type;
	int		line_cnt;
	char	*buf;

	line_cnt = -1;
	buf = get_next_line(fd);
	if (buf == NULL)
	{
		if (errno == ENOMEM)
			return (line_cnt);
		return (0);
	}
	pfx_type = mrt_int_extract_valid_prefix(buf, scene, handlers);
	if (-1 < pfx_type)
	{
		if (handlers[(unsigned int)pfx_type].hdl(scene, buf))
			line_cnt = mrt_int_set_array(scene, fd, handlers);
		else if (errno == 0)
			puterr_str(ERR_INVALID_VALUE, buf);
		if (-1 < line_cnt)
			line_cnt++;
	}
	free(buf);
	return (line_cnt);
}

int	mrt_read_file(t_scene *scene, const char *path)
{
	int				fd;
	int				line_cnt;
	const t_pfx_hdl	handlers[] = {
	{mrt_int_parse_handle_a, "A"},
	{mrt_int_parse_handle_c, "C"},
	{mrt_int_parse_handle_l, "L"},
	{mrt_int_parse_handle_pl, "pl"},
	{mrt_int_parse_handle_sp, "sp"},
	{mrt_int_parse_handle_cy, "cy"},
	{mrt_int_parse_handle_default, "#"},
	{mrt_int_parse_handle_default, NULL} /* feedback */};

	if (has_extension(path, RT_FILE_EXTENSION) == false)
		return (ret_errmsg(-1, ERR_INVALID_EXTENSION));
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (fd);
	line_cnt = mrt_int_set_array(scene, fd, handlers);
	close(fd);
	return (line_cnt);
}
