/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_scene.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:12:40 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/08/07 14:13:14 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_SCENE_H
# define TYPES_SCENE_H

# include <stdlib.h>

# include "libarith.h"

typedef struct s_scene	t_scene;
typedef struct s_ray	t_ray;

typedef union u_argb
{
	unsigned int		value;
	struct
	{
		unsigned char	b;
		unsigned char	g;
		unsigned char	r;
		unsigned char	a;
	}	s_c;
}	t_argb;

typedef enum e_parse_prefix_index
{
	PFX_AMBIENT,
	PFX_PERSPECTIVE,
	PFX_LIGHT,
	PFX_PLANE,
	PFX_SPHERE,
	PFX_CYLINDER,
	PFX_COMMENTOUT,
	PFX_UNKNOWN
}	t_parse_pfx_id;

typedef enum e_type_camera
{
	CAM_PERSPECTIVE,
	CAM_UNKNOWN
}	t_type_cam;

typedef enum e_type_light
{
	LGT_AMBIENT,
	LGT_POINT,
	// LGT_SPOT,
	LGT_UNKNOWN
}	t_type_lgt;

typedef enum e_type_object
{
	OBJ_SPHERE,
	OBJ_PLANE,
	OBJ_CYLINDER,
	// OBJ_QUADRIC,
	OBJ_UNKNOWN
}	t_type_obj;

typedef struct s_base_camera
{
	t_type_cam	type;
	t_coord3	pos;
	t_vec3		view;
}	t_base_cam;

typedef struct s_base_light
{
	unsigned int	(*diffuse)(t_scene *, const t_ray *, void *, t_vec3);
	t_type_lgt		type;
	t_argb			col;
	unsigned char	bright;
}	t_base_lgt;

typedef struct s_base_object
{
	float			(*intersect)(const t_ray *, void *);
	t_vec3			(*normal)(const t_ray *, void *);
	t_type_obj		type;
	t_coord3		pos;
	t_argb			col;
}	t_base_obj;

typedef struct s_camera_perspective
{
	t_base_cam	base;
	int			fov;
	float		focal_length;
	t_quat		cam_rot;
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
	float		r;
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

#endif /* TYPES_SCENE_H */
