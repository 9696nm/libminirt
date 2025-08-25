/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_read_file.c                                    :+:      :+:    :+:   */
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

static int	mrt_int_extract_valid_prefix(const char *buf, t_scene *vars,
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
	pfx_type = mrt_int_extract_valid_prefix(buf, vars, handlers);
	if (-1 < pfx_type)
	{
		if (handlers[(unsigned int)pfx_type].hdl(vars, buf))
			line_cnt = mrt_int_set_array(vars, fd, handlers);
		else if (errno == 0)
			dprintf(STDERR_FILENO, ERR_INVALID_VALUE, buf);
		if (-1 < line_cnt)
			line_cnt++;
	}
	free(buf);
	return (line_cnt);
}

int	mrt_read_file(t_scene *vars, char *path)
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
	line_cnt = mrt_int_set_array(vars, fd, handlers);
	close(fd);
	return (line_cnt);
}
