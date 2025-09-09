/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_ray.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:12:40 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/08/07 14:13:14 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_RAY_H
# define TYPES_RAY_H

# include <stdlib.h>

# include "libarith.h"

typedef struct s_base_object	t_base_obj;

typedef struct s_ndc
{
	float	x;
	float	y;
}	t_ndc;

typedef struct s_ray
{
	t_base_cam	*cam;
	t_base_obj	*colision;
	float		distance;
	t_vec3		raycast;
	t_vec3		reflex;
}	t_ray;

#endif /* TYPES_RAY_H */
