/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 23:37:52 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/30 23:22:48 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
#define SO_LONG_BONUS_H

#include "../libft/inc/libft.h"
#include "../libft/inc/colors.h"
#include "../libft/inc/ft_printf.h"
#include "../libft/inc/error.h"

#define MSG_DAN_0 "Error 0: Missing map"
#define MSG_DAN_1 "Error 1: Too many arguments"
#define MSG_DAN_2 "Error 2: File map does not have the extension .ber"
#define MSG_WAR_0 "Warning 0: Different length of lines"
#define MSG_WAR_1 "Warning 1: Need one 'P' for player on the map"
#define MSG_WAR_2 "Warning 2: Need one 'E' for exit on the map"
#define MSG_WAR_3 "Warning 3: There is no collectable on the map"
#define MSG_WAR_4 "Warning 4: Invalid character in map"
#define MSG_WAR_5 "Warning 5: The map is not closed"
#define MSG_WAR_6 "Warning 6: The map does not have a correct path"
#define MSG_WAR_7 "Warning 7: Need one 'X' for enemy on the map"

#define SQUARE 32
#define HEADER 64

enum
{
	ON_KEYPRESS = 2,
	ON_KEYRELEASE = 3,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_images
{
	char *gwall[8];
	char *floor[1];
	char *wall[8];
	char *hero[4];
	char *door[2];
	char *logo[1];
	char *header[4];
	char *mom[4];
} t_images;

typedef struct s_scp
{
	int x;
	int y;
} t_scp;

typedef struct s_objs
{
	int goals;
	int get;
	int move;
	t_scp player;
	t_scp exit;
	t_scp enemy;
} t_objs;

typedef struct s_map
{
	char **map;
	char **tmp;
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

void err_file(int n, char *file);
void init_img(t_game *game);
void filter_map(t_game *game, int x, int y, char ch);
void ctrl_map(t_game *game);
int ctrl_wall(t_map map, int rows, int cols, char ch);
void ctrl_path(t_game *game);
void ctrl_move(t_game *game);
void lap_map(t_game *game, void (*function)(t_game *game, int x, int y, char ch));
void locate(t_game *game, int x, int y, char ch);
void move(t_game *game, int x, int y, int type);
void header(t_game *game);

//	CUIDA SIN USO
int reload(t_game *game);
void pasada_dos(t_game *game, int x, int y, char ch);
void re_floor(t_game *game, int x, int y, char ch);
int free_map(t_game *game);
#endif
