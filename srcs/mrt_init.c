/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:55:19 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/07/08 18:55:20 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_int.h"

t_scene	*mrt_init(void)
{
	t_scene	*vars;

	vars = malloc(sizeof(t_scene));
	return (vars);
}
