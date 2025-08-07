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

# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# include "ft/ctype.h"
# include "ft/string.h"
# include "ft/stdio.h"
# include "get_next_line.h"
# include "libarith.h"

# include "scene_types.h"

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

typedef struct s_scene
{
	t_lgt_base		*lights[MAX_LIGHTS];
	unsigned int	num_lgt;
	t_obj_base		*objects[MAX_OBJECTS];
	unsigned int	num_obj;
	u_int32_t		pfx_used_bits;

}	t_scene;

typedef struct s_prefix_handler
{
	const char	*pfx;
	int			(*hdl)(t_scene *, char *);
}	t_pfx_hdl;

/* mrt_int_handler.c */
int	handle_a(t_scene *vars, char *str);
int	handle_c(t_scene *vars, char *str);
int	handle_l(t_scene *vars, char *str);
int	handle_pl(t_scene *vars, char *str);
int	handle_sp(t_scene *vars, char *str);
int	handle_cy(t_scene *vars, char *str);
int	handle_default(t_scene *vars, char *str);

#endif /* MINIRT_INT_H */