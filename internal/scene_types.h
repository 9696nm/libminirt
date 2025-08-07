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

typedef enum e_light_type
{
	LGT_AMBIENT,
	LGT_POINT,
	LGT_SPOT,
	LGT_UNKNOWN
}	t_lgt_type;

typedef struct s_light_base
{
	t_lgt_type		type;
	u_int8_t		bright;
	unsigned int	col;

	void			(*intersect)(void *self);
	void			(*destroy)(void *self);
}	t_lgt_base;

typedef struct s_ambient_lighting
{
	t_lgt_base	base;
}	t_amb_lgt;

typedef struct s_point_lighting
{
	t_lgt_base	base;
	t_coord3	pos;
}	t_pt_lgt;

typedef enum e_object_type
{
	OBJ_SPHERE,
	OBJ_PLANE,
	OBJ_CYLINDER,
	OBJ_QUADRIC,
	OBJ_UNKNOWN
}	t_obj_type;

typedef struct s_object_base
{
	t_obj_type		type;
	t_coord3		pos;
	unsigned int	col;

	void			(*intersect)(void *self);
	void			(*destroy)(void *self);
}	t_obj_base;

typedef struct s_camera_object
{
	t_obj_base	base;
	t_vec3		view;
	float		fov;
}	t_cam_obj;

typedef struct s_sphere_object
{
	t_obj_base	base;
	float		d;
}	t_sph_obj;

typedef struct s_plane_object
{
	t_obj_base	base;
	t_vec3		normal;
}	t_pln_obj;

typedef struct s_cylinder_object
{
	t_obj_base	base;
	t_vec3		axis;
	float		d;
	float		h;
}	t_cyl_obj;

#endif /* SCENE_TYPES_H */
