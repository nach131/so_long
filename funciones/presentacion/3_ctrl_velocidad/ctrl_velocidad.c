/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_velocidad.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:55:59 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/02/13 11:10:07 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "../../../sources/mlx/mlx.h"
#include "../../../sources/libft/inc/libft.h"
#include <unistd.h>
#include <stdlib.h>

#define SQUARE 32
#define LEN_X 7
#define LEN_Y 3

int g_loop = 1;

enum
{
	ON_KEYPRESS = 2,
	ON_KEYRELEASE = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum
{
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_W = 13,
	KEY_1 = 18,
	KEY_2 = 19,
	KEY_ESC = 53
};

enum
{
	HERO,
	FLOOR,
};

typedef struct s_graphic
{
	void *mlx;
	void *win;
	void *img;
	void *rabbit[8];
	void *floor[1];
} t_graphic;

typedef struct s_game
{
	t_graphic graphic;
	int flag;
	int type;
} t_game;

int key_push(int key, t_game *game)
{
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_A)
	{
		write(1, "A", 1);
		g_loop = 0;
	}
	else if (key == KEY_S)
	{
		write(1, "S", 1);
		g_loop = 1;
	}
	else if (key == KEY_1)
		mlx_loop_hook(game->graphic.mlx, NULL, NULL);

	return (0);
}

void put_uno(t_game *game)
{
	int static i = 0;
	int static frame = 0;
	if (!(frame % 100))
	{
		mlx_put_image_to_window(game->graphic.mlx, game->graphic.win,
								game->graphic.rabbit[i], 4 * SQUARE, SQUARE);
		i++;
		if (i == 7)
			i = 0;
		frame = 1;
	}
	else
		frame++;
}
void put_dos(t_game *game)
{
	int static i = 0;
	int static frame = 0;
	if (!(frame % 300))
	{
		mlx_put_image_to_window(game->graphic.mlx, game->graphic.win,
								game->graphic.rabbit[i], 5 * SQUARE, SQUARE);
		if (i == 7)
			i = 0;
		i++;
		frame = 1;
	}
	else
		frame++;
}

void loops(t_game *game)
{

	int static a = 0;
	int static b = 0;
	int static c = 0;
	int static framea = 0;
	int static frameb = 0;
	int static framec = 0;

	// CADA FUNCION DE ANIMADO TIENE QUE TENER SU PROPIO FRAME

	if (g_loop)
	{
		if (!(framea % 100))
		{
			mlx_put_image_to_window(game->graphic.mlx, game->graphic.win,
									game->graphic.rabbit[a], SQUARE, SQUARE);
			if (a == 7)
				a = 0;
			a++;
			framea = 1;
		}
		if (!(frameb % 300))
		{
			mlx_put_image_to_window(game->graphic.mlx, game->graphic.win,
									game->graphic.rabbit[b], 2 * SQUARE, SQUARE);
			b++;
			if (b == 7)
				b = 0;
			frameb = 1;
		}
		if (!(framec % 600))
		{
			mlx_put_image_to_window(game->graphic.mlx, game->graphic.win,
									game->graphic.rabbit[c], 3 * SQUARE, SQUARE);
			if (c == 7)
				c = 0;
			c++;
			framec = 1;
		}
		else
		{
			framea++;
			frameb++;
			framec++;
		}
		put_uno(game);
		put_dos(game);
	}
}

char static *path_img(char *name_img, int n)
{
	char *nbr;
	char *s1;
	char *s2;

	nbr = ft_itoa(n);
	s1 = ft_strjoin("../../../sources/xpm/", name_img);
	s2 = ft_strjoin(s1, "/");
	free(s1);
	s1 = ft_strjoin(s2, name_img);
	free(s2);
	s2 = ft_strjoin(s1, nbr);
	free(s1);
	s1 = ft_strjoin(s2, ".xpm");
	free(s2);
	free(nbr);
	return (s1);
}

void static load_image(t_game *game, char *name, int num, int type)
{
	int i;
	int w;
	int h;
	void *mlx = game->graphic.mlx;
	char *path;

	i = -1;

	while (++i < num)
	{
		path = path_img(name, i);
		if (type == HERO)
			game->graphic.rabbit[i] = mlx_xpm_file_to_image(game->graphic.mlx, path, &w, &h);
		else if (type == FLOOR)
			game->graphic.floor[i] = mlx_xpm_file_to_image(game->graphic.mlx, path, &w, &h);
		free(path);
	}
}

void put_floor(t_game *game)
{
	int x = 0;
	int y = 0;
	while (y <= LEN_Y)
	{
		while (x < LEN_X)
		{
			mlx_put_image_to_window(game->graphic.mlx, game->graphic.win,
									game->graphic.floor[0], x * SQUARE, y * SQUARE);
			x++;
		}
		x = 0;
		y++;
	}
}

void presentacion(t_game *game)
{
	load_image(game, "rabbit_r", 8, HERO);
	load_image(game, "floor", 1, FLOOR);

	game->graphic.win = mlx_new_window(game->graphic.mlx,
									   LEN_X * SQUARE, LEN_Y * SQUARE, "nach131 So Long");

	put_floor(game);

	mlx_hook(game->graphic.win, ON_DESTROY, 1L << 0, (void *)exit, game);

	// mlx_loop_hook(game->graphic.mlx, NULL, game);
	mlx_loop_hook(game->graphic.mlx, (void *)&loops, game);
}

int main(void)
{
	t_game game;
	ft_bzero(&game, sizeof(t_game));
	game.graphic.mlx = mlx_init();
	presentacion(&game);
	mlx_hook(game.graphic.win, ON_KEYPRESS, 1L << 0, &key_push, &game);

	mlx_loop(game.graphic.mlx);
	return (0);
}

//  gcc -framework OpenGL -framework AppKit ctrl_velocidad.c ../../../sources/mlx/libmlx.a ../../../sources/libft/libft.a
