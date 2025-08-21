/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_types.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:12:40 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/08/07 14:13:14 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_TYPES_H
# define SCENE_TYPES_H

# include <stdlib.h>

# include "libarith.h"

typedef enum e_type_camera
{
	CAM_PERSPECTIVE,
	CAM_UNKNOWN
}	t_type_cam;

typedef struct s_base_camera
{
	void		(*intersect)(void *self);
	void		(*destroy)(void *self);

	t_type_cam	type;
	t_coord3	pos;
	t_vec3		view;
}	t_base_cam;

typedef enum e_type_light
{
	LGT_AMBIENT,
	LGT_POINT,
	// LGT_SPOT,
	LGT_UNKNOWN
}	t_type_lgt;

typedef struct s_base_light
{
	void			(*intersect)(void *self);
	void			(*destroy)(void *self);

	t_type_lgt		type;
	unsigned int	col;
	unsigned char	bright;
}	t_base_lgt;

typedef enum e_type_object
{
	OBJ_SPHERE,
	OBJ_PLANE,
	OBJ_CYLINDER,
	// OBJ_QUADRIC,
	OBJ_UNKNOWN
}	t_type_obj;

typedef struct s_base_object
{
	void			(*intersect)(void *self);
	void			(*destroy)(void *self);

	t_type_obj		type;
	t_coord3		pos;
	unsigned int	col;
}	t_base_obj;

typedef struct s_camera_perspective
{
	t_base_cam	base;
	float		fov;
}	t_cam_persp;

typedef struct s_light_ambient
{
	t_base_lgt	base;
}	t_lgt_amb;

typedef struct s_light_point
{
	t_base_lgt	base;
	t_coord3	pos;
}	t_lgt_pt;

typedef struct s_object_sphere
{
	t_base_obj	base;
	float		d;
}	t_obj_sph;

typedef struct s_object_plane
{
	t_base_obj	base;
	t_vec3		normal;
}	t_obj_pln;

typedef struct s_object_cylinder
{
	t_base_obj	base;
	t_vec3		axis;
	float		d;
	float		h;
}	t_obj_cyl;

#endif /* SCENE_TYPES_H */
