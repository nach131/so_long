/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 23:37:52 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/23 16:24:48 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "../libft/inc/libft.h"
#include "../libft/inc/colors.h"
#include "../libft/inc/ft_printf.h"
#include "../libft/inc/error.h"
// #include "mlx.h"

#define MSG_DAN_0 "Error 0: Missing map"
#define MSG_DAN_1 "Error 1: Too many arguments"
#define MSG_DAN_2 "Error 2: File map does not have the extension .ber"

#define MSG_WAR_0 "Warning 0: Different length of lines"
#define MSG_WAR_6 "Warning 6: More than one (exit or player) found"

#define MSG_WAR_2 "Warning 2: There is no player on the map"
#define MSG_WAR_3 "Warning 3: There is no exit on the map"
#define MSG_WAR_4 "Warning 4: There is no collectable on the map"

#define MSG_WAR_5 "Warning 5: The map is not closed"

#define MSG_WAR_1 "Warning 1: The map cannot be square"

// #define WALL '1'
// #define EMPTY '0'
// #define COL 'C'
// #define EXIT 'E'
// #define PLAYER 'P'
// #define ENEMY 'X'
#define SQUARE 32

enum
{
	ON_KEYPRESS = 2,
	ON_KEYRELEASE = 3,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum
{
	GWALL,
	FLOOR,
};

typedef struct s_images
{
	char *gwall[8];
	char *floor[1];
} t_images;

typedef struct s_scp
{
	int x;
	int y;
} t_scp;

typedef struct s_objs
{
	int goals;
	t_scp exit;
	t_scp player;
} t_objs;

typedef struct s_map
{
	char **map;
	int cols;
	int rows;
	t_objs objets;
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
	t_images images;
} t_game;

// int strlen_line(char *line);
// void ctrl_square(t_map *map);
void err_file(int n, char *file);
// void ctrl_map(t_map *map, char *line);
// void open_map(char *path, t_map *map);
void filter_map(t_game *game, int x, int y, char ch);
void read_map(t_game *game);
void init_img(t_game *game);
void control_map(t_game *game);

#endif
