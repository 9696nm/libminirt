/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_int.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:55:25 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/07/08 18:55:26 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_INT_H
# define MINIRT_INT_H

# include <errno.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# include "mlx.h"

# include "ft/ctype.h"
# include "ft/stdio.h"
# include "ft/stdlib.h"
# include "ft/string.h"
# include "get_next_line.h"
# include "libarith.h"

# include "scene_types.h"

# define MAX_CAMERAS 4
# define MAX_LIGHTS 8
# define MAX_OBJECTS 128
# define RT_FILE_EXTENSION ".rt"

/* error messege */
# define ERR_INVALID_EXTENSION "Error: scene file must have a '.rt' \
extension.\n"
# define ERR_NO_MATCHING_PREFIX "Error: no matching prefix found \
for the given input.\n"
# define ERR_MULTIPLE_UNIQUE_PREFIXES "Error: multiple mutually-exclusive \
prefixes detected.\n"
# define ERR_INVALID_VALUE "Error: invalid value detected in line \"%s\".\n"

typedef struct s_scene
{
	t_base_cam		*cameras[MAX_CAMERAS];
	unsigned int	num_cam;
	t_base_lgt		*lights[MAX_LIGHTS];
	unsigned int	num_lgt;
	t_base_obj		*objects[MAX_OBJECTS];
	unsigned int	num_obj;
	u_int32_t		pfx_used_bits;

	void			*mlx;
	void			*win;
}	t_scene;

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

/* mrt_int_parse_handler */
int		mrt_int_parse_handle_a(t_scene *vars, const char *str);
int		mrt_int_parse_handle_c(t_scene *vars, const char *str);
int		mrt_int_parse_handle_l(t_scene *vars, const char *str);
int		mrt_int_parse_handle_pl(t_scene *vars, const char *str);
int		mrt_int_parse_handle_sp(t_scene *vars, const char *str);
int		mrt_int_parse_handle_cy(t_scene *vars, const char *str);
int		mrt_int_parse_handle_default(t_scene *vars, const char *str);

/* mrt_int_parse_str */
int		mrt_int_parse_str_split(const char *src, const t_fp_maps *map);
int		mrt_int_parse_str_bright(const char *str, void *ptr);
int		mrt_int_parse_str_ufloat(const char *str, void *ptr);
int		mrt_int_parse_str_fov(const char *str, void *ptr);
int		mrt_int_parse_str_color(const char *str, void *ptr);
int		mrt_int_parse_str_coord(const char *str, void *ptr);
int		mrt_int_parse_str_vecter3(const char *str, void *ptr);

/* !!!!! debug !!!!! */
void	mrt_int_debug_print_cam(t_base_cam *ptr);
void	mrt_int_debug_print_lgt(t_base_lgt *ptr);
void	mrt_int_debug_print_obj(t_base_obj *ptr);

#endif /* MINIRT_INT_H */
