/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_render.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:12:40 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/08/07 14:13:14 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_RENDER_H
# define UTILS_RENDER_H

# include <float.h>
# include <stdlib.h>
# include <math.h>

# include "libarith.h"
# include "types_scene.h"
# include "types_transform.h"

# define FOCAL_LENGTH_MAX 1e6f

typedef struct s_scene	t_scene;

typedef t_vec3			(*t_trance)(t_base_cam *, t_ndc, float);


/* mrt_int_pixel_color */
unsigned int	mrt_int_pixel_color(t_scene *scene, int x, int y);

/* mrt_int_pixel_raycast */
int				mrt_int_pixel_raycast(t_vec3 *raycast,
					t_scene *scene, int x, int y);
t_vec3			mrt_int_pixel_raycast_perspective(t_base_cam *cam,
					t_ndc ndc, float aspect);

/* mrt_int_ray_focal_from_fov */
float			mrt_int_ray_focal_from_fov(int fov);

/* mrt_int_get_cam_type */
t_base_cam		*mrt_int_get_cam_type(t_scene *scene);

#endif /* UTILS_RENDER_H */
