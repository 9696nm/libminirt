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


#endif /* TYPES_CALCULATE_H */
