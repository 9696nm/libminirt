/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:10:52 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/07/08 16:46:55 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H



void	mrt_destroty(void *vars);

void	*mrt_init(void);
int		mrt_set_value(void *vars, char *path);

#endif /* MINIRT_H */ 
