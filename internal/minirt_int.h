/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_int.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:55:25 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/08/26 14:51:57 by hana/hmori       ###   ########.fr       */
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

# include "ft/ctype.h"
# include "ft/stdio.h"
# include "ft/stdlib.h"
# include "ft/string.h"
# include "get_next_line.h"
# include "libarith.h"

# include "types_scene.h"
# include "types_transform.h"


/* number of scene */
# define MAX_CAMERAS 4
# define MAX_LIGHTS 8
# define MAX_OBJECTS 128

/*  error messege  */
# define ERR_INVALID_EXTENSION "Error: scene file must have a '.rt' \
extension.\n"
# define ERR_NO_MATCHING_PREFIX "Error: no matching prefix found \
for the given input.\n"
# define ERR_MULTIPLE_UNIQUE_PREFIXES "Error: multiple mutually-exclusive \
prefixes detected.\n"
# define ERR_INVALID_VALUE "Error: invalid value detected in line \"%s\".\n"
# define ERR_NO_MATCHING_CAMERA_INDEX "Error: no matching camera indices \
\"%d\".\n"

typedef struct s_scene
{
	t_base_cam		*cameras[MAX_CAMERAS];
	unsigned int	num_cam;
	t_base_lgt		*lights[MAX_LIGHTS];
	unsigned int	num_lgt;
	t_base_obj		*objects[MAX_OBJECTS];
	unsigned int	num_obj;
	u_int32_t		pfx_used_bits;

	unsigned int	cam_type;

	unsigned int	width;	// need?
	unsigned int	height;

	float			aspect_ratio;
	t_ndc			ndc_norm;
}	t_scene;

/* !!!!! debug !!!!! */
void	mrt_int_debug_print_cam(t_base_cam *ptr);
void	mrt_int_debug_print_lgt(t_base_lgt *ptr);
void	mrt_int_debug_print_obj(t_base_obj *ptr);

#endif /* MINIRT_INT_H */
