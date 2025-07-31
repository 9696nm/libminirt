
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

typedef enum e_object_type
{
	OBJ_SPHERE,
	OBJ_PLANE,
	OBJ_CYLINDER,
	OBJ_QUADRIC,
	OBJ_UNKNOWN
}	t_obj_type;

typedef struct s_light_base
{
	t_lgt_type		type;
	u_int8_t		bright;
	unsigned int	col;

	void	(*intersect)(void *self);
	void	(*destroy)(void *self);
}	t_lgt_base;

typedef struct s_object_base
{
	t_obj_type		type;
	t_coord3		pos;
	unsigned int	col;

	void	(*intersect)(void *self);
	void	(*destroy)(void *self);
}	t_obj_base;

typedef struct s_ambient_lighting
{
	t_lgt_base	base;
}	t_amb_lgt;

typedef struct s_point_lighting
{
	t_lgt_base	base;
	t_coord3	pos;
}	t_pt_lgt;

typedef struct s_camera
{
	t_obj_base	base;
	t_vec3		view;
	float		fov;
}	t_camera;

typedef struct s_sphere
{
	t_obj_base	base;
	float		d;
}	t_sphere;

typedef struct s_plane
{
	t_obj_base	base;
	t_vec3		normal;
}	t_plane;

typedef struct s_cylinder
{
	t_obj_base	base;
	t_vec3		axis;
	float		d;
	float		h;
}	t_cylinder;

#endif /* SCENE_TYPES_H */