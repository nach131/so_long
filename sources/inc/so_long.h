/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 23:37:52 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/05 23:02:44 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "../libft/inc/libft.h"
#include "../libft/inc/colors.h"
#include "../libft/inc/ft_printf.h"
#include "../libft/inc/error.h"

#define MSG_DAN_0 "Error 0: Missing map"
#define MSG_DAN_1 "Error 1: Too many arguments"
#define MSG_WAR_0 "Warning 0: Different length of lines"

#define WALL '1'
#define EMPTY '0'
#define COL 'C'
#define EXIT 'E'
#define PLAYER 'P'
#define ENEMY 'X'
#define SQUARE 32

// sistema de coordenadas personales

typedef struct s_scp
{
	int x;
	int y;
} t_scp;

typedef struct s_map
{
	int open;
	int write;
	char **map;
	int cols;
	int rows;
	t_scp player;
} t_map;

typedef struct s_grafic
{
	void *mlx;
	void *win;
	void *img;
} t_grafic;

typedef struct s_game
{
	t_grafic grafic;
	t_map map;
} t_game;

void arr_to_lst(void);
void err_file(int n);
void open_map(char *path, t_map *map);

#endif
