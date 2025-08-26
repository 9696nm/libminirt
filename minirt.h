/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:10:52 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/08/26 15:15:51 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

void	mrt_destroty(void *scene);

void	*mrt_init(void);
int		mrt_loop(void *scene);
int		mrt_read_file(const char *path, void *scene);

#endif /* MINIRT_H */ 
