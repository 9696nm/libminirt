/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_int.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:55:25 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/07/08 18:55:26 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_INT_H
# define MINIRT_INT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

# include "ft/stdio.h"
# include "libarith.h"

# include "scene_types.h"

# define MAX_LIGHTS 8
# define MAX_OBJECTS 128
# define RT_FILE_EXTENSION ".rt"

/* error messege */
# define ERR_INVALID_EXTENSION "Error: scene file must have a '.rt' \
extension.\n"

typedef struct s_prefix_handler
{
	const char	*prefix;
	void		(*handler)(void);
}	t_prefix_handler;

typedef struct s_scene
{
	t_lgt_base		*lights[MAX_LIGHTS];
	unsigned int	num_lgt;
	t_obj_base		*objects[MAX_OBJECTS];
	unsigned int	num_obj;

}	t_scene;

/*  */
void	handle_A(void);
void	handle_C(void);
void	handle_L(void);
void	handle_pl(void);
void	handle_sp(void);
void	handle_cy(void);
void	handle_default(void);

#endif /* MINIRT_INT_H */