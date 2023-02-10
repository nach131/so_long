/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_dos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:55:59 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/02/10 20:22:25 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "../../../sources/mlx/mlx.h"
#include "../../../sources/libft/inc/libft.h"
#include <unistd.h>
#include <stdlib.h>

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

#define KEY_ESC 53
#define KEY_1 18
#define KEY_2 19

#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define KEY_W 13

int g_loop = 1;

typedef struct s_grafic
{
	void *mlx;
	void *win;
	void *img;
	void *rabbit[8];
} t_grafic;

typedef struct s_game
{
	t_grafic grafic;
	int flag;
	int type;
} t_game;

void ft_free_map(t_game *game)
{
	int i = -1;
	if (game->grafic.rabbit[0])
		while (++i < 8)
		{
			mlx_destroy_image(game->grafic.mlx, game->grafic.rabbit[i]);
			game->grafic.rabbit[i] = NULL;
		}
	mlx_destroy_window(game->grafic.mlx, game->grafic.win);
	exit(0);
}

int key_push(int key, t_game *game)
{
	if (key == KEY_ESC)
		// ft_free_map(game);
		exit(0);
	if (key == KEY_A)
	{
		write(1, "A", 1);
		g_loop = 0;
	}
	if (key == KEY_S)
	{
		write(1, "S", 1);
		g_loop = 1;
	}
	if (key == KEY_1)
		mlx_loop_hook(game->grafic.mlx, NULL, NULL);
	if (key == KEY_2)
		write(1, "Es dos\n", 7);
	return (0);
}

void put_uno(t_game *game)
{
	int static i = 0;
	int static frame = 0;
	if (!(frame % 100))
	{
		mlx_put_image_to_window(game->grafic.mlx, game->grafic.win, game->grafic.rabbit[i], 94, 0);
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
		mlx_put_image_to_window(game->grafic.mlx, game->grafic.win, game->grafic.rabbit[i], 126, 0);
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
	// mlx_put_image_to_window(game->grafic.mlx, game->grafic.win, game->grafic.rabbit[0], 0, 0);

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
			mlx_put_image_to_window(game->grafic.mlx, game->grafic.win, game->grafic.rabbit[a], 0, 0);
			if (a == 7)
				a = 0;
			a++;
			framea = 1;
		}
		if (!(frameb % 300))
		{
			mlx_put_image_to_window(game->grafic.mlx, game->grafic.win, game->grafic.rabbit[b], 32, 0);
			b++;
			if (b == 7)
				b = 0;
			frameb = 1;
		}
		if (!(framec % 600))
		{
			mlx_put_image_to_window(game->grafic.mlx, game->grafic.win, game->grafic.rabbit[c], 64, 0);
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
	void *mlx = game->grafic.mlx;
	char *path;

	i = -1;

	while (++i < num)
	{
		path = path_img(name, i);
		if (type == 1)
			game->grafic.rabbit[i] = mlx_xpm_file_to_image(game->grafic.mlx, path, &w, &h);
		// else if (type == 2)
		// 	game->images.won[i] = mlx_xpm_file_to_image(game->grafic.mlx, path, &w, &h);
		free(path);
	}
}

void presentacion(t_game *game)
{
	load_image(game, "rabbit_r", 8, 1);

	game->grafic.win = mlx_new_window(game->grafic.mlx, 20 * 32, 15 * 32, "nach131 So Long");

	mlx_loop_hook(game->grafic.mlx, &loops, game);
}

int main(void)
{
	t_game game;
	ft_bzero(&game, sizeof(t_game));
	game.grafic.mlx = mlx_init();
	presentacion(&game);
	mlx_hook(game.grafic.win, ON_KEYPRESS, 1L << 0, &key_push, &game);
	mlx_loop(game.grafic.mlx);
	return (0);
}

//  gcc -framework OpenGL -framework AppKit main_dos.c ../../../sources/mlx/libmlx.a ../../../sources/libft/libft.a
