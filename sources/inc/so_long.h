/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 23:37:52 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/02/11 00:31:27 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/inc/libft.h"
# include "../libft/inc/colors.h"
# include "../libft/inc/ft_printf.h"
# include "../libft/inc/error.h"

# define MSG_DAN_0 "Error 0: Missing map"
# define MSG_DAN_1 "Error 1: Too many arguments"
# define MSG_DAN_2 "Error 2: File map does not have the extension .ber"
# define MSG_WAR_0 "Warning 0: Different length of lines"
# define MSG_WAR_1 "Warning 1: Need one 'P' for player on the map"
# define MSG_WAR_2 "Warning 2: Need one 'E' for exit on the map"
# define MSG_WAR_3 "Warning 3: There is no collectable on the map"
# define MSG_WAR_4 "Warning 4: Invalid character in map"
# define MSG_WAR_5 "Warning 5: The map is not closed"
# define MSG_WAR_6 "Warning 6: The map does not have a correct path"

# define SQUARE 32
# define HEADER 64

enum
{
	ON_KEYPRESS = 2,
	ON_DESTROY = 17,
};

enum
{
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_W = 13,
	KEY_R = 15,
	KEY_ONE = 18,
	KEY_TWO = 19,
	KEY_THREE = 20,
	KEY_FOUR = 21,
	KEY_ESC = 53,
	KEY_LEFT = 123,
	KEY_RIGHT = 124,
	KEY_DOWN = 125,
	KEY_UP = 126,
};

enum
{
	RIGHT,
	LEFT,
	DOWN,
	UP,
};

typedef struct s_images
{
	char	*gwall[8];
	char	*floor[1];
	char	*wall[8];
	char	*hero[4];
	char	*door[4];
	char	*logo[1];
	char	*header[3];
}	t_images;

typedef struct s_scp
{
	int	x;
	int	y;
}	t_scp;

typedef struct s_objs
{
	int		goals;
	int		get;
	int		move;
	char	*movements;
	t_scp	player;
	t_scp	exit;
}	t_objs;

typedef struct s_map
{
	char	**map;
	char	**tmp;
	int		cols;
	int		rows;
	t_objs	objets;
}	t_map;

typedef struct s_graphic
{
	void	*mlx;
	void	*win;
	void	*img;
}	t_graphic;

typedef struct s_game
{
	t_graphic	graphic;
	t_map		map;
	t_images	images;
}	t_game;

void	err_file(int n, char *file);
void	init_img(t_game *game);
void	filter_map(t_game *game, int x, int y, char ch);
void	ctrl_map(t_game *game);
int		ctrl_wall(t_map map, int rows, int cols, char ch);
void	ctrl_path(t_game *game);
void	ctrl_move(t_game *game);
void	lap_map(t_game *game, void (*function)(t_game *game, int x,
				int y, char ch));
void	locate(t_game *game, int x, int y, char ch);
void	move(t_game *game, int x, int y, int type);
void	header(t_game *game);
void	intro(t_game *game);
void	star_game(t_game *game);
void	load_img(t_game *game, char *name, int num, int type);

#endif
