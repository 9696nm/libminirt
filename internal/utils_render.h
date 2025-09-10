/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_render.h                                     :+:      :+:    :+:   */
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
# include "types_calculate.h"
# include "types_scene.h"
# include "types_ray.h"

# define FOCAL_LENGTH_MAX 1e6f

typedef struct s_scene	t_scene;

typedef t_vec3			(*t_trance)(t_base_cam *, t_ndc, float);

/* mrt_int_pixel_color */
unsigned int	mrt_int_pixel_color(t_scene *scene, int x, int y);

/* mrt_int_pixel_raycast */
int				mrt_int_pixel_raycast(t_scene *scene,
					t_ray *raycast, int x, int y);
t_vec3			mrt_int_pixel_raycast_perspective(t_base_cam *cam,
					t_ndc ndc, float aspect);

/* mrt_int_intersect_search */
int				mrt_int_intersect_search(t_scene *scene, t_ray *ray);
float			mrt_int_intersect_sp(const t_ray *ray, void *self);
float			mrt_int_intersect_pl(const t_ray *ray, void *self);
float			mrt_int_intersect_cy(const t_ray *ray, void *self);

/* mrt_int_lighting */
unsigned int	mrt_int_calculate_lighting(t_scene *scene, t_ray *ray);
int				mrt_int_is_in_shadow(t_scene *scene,
					t_vec3 normal, t_dif_cal v);

/* mrt_int_ray_light_diffuse */
unsigned int	mrt_int_ray_light_diffuse_pt(t_scene *scene, const t_ray *ray,
					void *self, t_vec3 normal);

/* mrt_int_ray_object_normal */
t_vec3			mrt_int_ray_object_normal_sp(const t_ray *ray, void *self);
t_vec3			mrt_int_ray_object_normal_pl(const t_ray *ray, void *self);
t_vec3			mrt_int_ray_object_normal_cy(const t_ray *ray, void *self);

/* mrt_int_ray_focal_from_fov */
float			mrt_int_ray_focal_from_fov(int fov);

#endif /* UTILS_RENDER_H */
