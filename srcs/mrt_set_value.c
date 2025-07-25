/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt_set_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:55:17 by hana/hmori        #+#    #+#             */
/*   Updated: 2025/07/08 18:55:18 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_int.h"

int		mrt_set_value(void *vars, char *path)
{
	int	fd;
	int	index;

	index = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (perrturn(-1, path));
	(void)vars;
	close(fd);
	return (index);
}
