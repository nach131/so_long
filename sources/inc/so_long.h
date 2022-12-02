/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 23:37:52 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/03 00:07:51 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "../libft/inc/libft.h"
#include "../libft/inc/colors.h"
#include "../libft/inc/ft_printf.h"
#include "../libft/inc/error.h"

typedef struct s_map
{
	int open;
	char **map;
	int cols;
	int rows;
} t_map;

typedef struct s_all
{
	t_map map;
} t_all;

void arr_to_lst(void);
void open_map(char *path, t_map *map);

#endif
