/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_calculate.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:12:40 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/08/07 14:13:14 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_CALCULATE_H
# define TYPES_CALCULATE_H

# include "libarith.h"

typedef struct s_diffuse_calculate
{
	float		dist;
	t_vec3		hit_point;
	t_vec3		light_dir;
}	t_dif_cal;

typedef struct s_quadratic_function
{
	float	a;
	float	b;
	float	c;
	float	disc;
	float	t;
	float	radius;
}	t_quad_func;

typedef struct t_cap_function
{
	float	normal_dot_raycast;
	float	t;
	t_vec3	hit_point;
	t_vec3	cap_to_hit;
	float	dist_sq;
	float	radius;
}	t_cap_func;

typedef struct t_cylinder_function
{
	t_vec3	hit_point;
	t_vec3	cylinder_to_hit;
	float	t_side;
	float	t_top;
	float	t_bottom;
	float	t_min;
	float	height_projection;
}	t_cy_func;

#endif /* TYPES_CALCULATE_H */
