/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:12:40 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/08/07 14:13:14 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_PARSE_H
# define UTILS_PARSE_H

# define RT_FILE_EXTENSION ".rt"

typedef struct s_scene	t_scene;

typedef struct s_prefix_handler
{
	int			(*hdl)(t_scene *, const char *);
	const char	*pfx;
}	t_pfx_hdl;

typedef struct s_func_ptr_maps
{
	int		(*fnc)(const char *, void *);
	void	*ptr;
}	t_fp_maps;

/* mrt_int_has_extension */
bool	has_extension(const char *path, const char *ext);

/* mrt_int_parse_handler */
int		mrt_int_parse_handle_a(t_scene *scene, const char *str);
int		mrt_int_parse_handle_c(t_scene *scene, const char *str);
int		mrt_int_parse_handle_l(t_scene *scene, const char *str);
int		mrt_int_parse_handle_pl(t_scene *scene, const char *str);
int		mrt_int_parse_handle_sp(t_scene *scene, const char *str);
int		mrt_int_parse_handle_cy(t_scene *scene, const char *str);
int		mrt_int_parse_handle_default(t_scene *scene, const char *str);

/* mrt_int_parse_str */
int		mrt_int_parse_str_split(const char *src, const t_fp_maps *map);
int		mrt_int_parse_str_bright(const char *str, void *ptr);
int		mrt_int_parse_str_ufloat(const char *str, void *ptr);
int		mrt_int_parse_str_fov(const char *str, void *ptr);
int		mrt_int_parse_str_color(const char *str, void *ptr);
int		mrt_int_parse_str_coord(const char *str, void *ptr);
int		mrt_int_parse_str_vecter3(const char *str, void *ptr);

#endif /* UTILS_PARSE_H */
