/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_dos_bis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:55:59 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/02/11 00:36:35 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "../../../sources/mlx/mlx.h"
#include "../../../sources/libft/inc/libft.h"
#include "../../../sources/libft/inc/colors.h"
#include "../../../sources/libft/inc/ft_printf.h"

#include <unistd.h>

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
#define KEY_3 20

#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define KEY_W 13

#define LOSE 103
#define WON 91

typedef struct s_images
{
	void *mom;
	void *lose[LOSE];
	char *won[WON];

} t_images;

typedef struct s_graphic
{
	void *mlx;
	void *win;
	void *img;
} t_graphic;

typedef struct s_game
{
	t_graphic graphic;
	t_images images;
	int flag;
	int type;
} t_game;

void segunda_lose(t_game *game);
void tercera_won(t_game *game);
void presentacion(t_game *game);
void free_all(t_game *game);

int key_push(int key, t_game *game)
{
	if (key == KEY_ESC)
		exit(0);
	if (key == KEY_A)
		write(1, "A", 1);
	if (key == KEY_1)
		presentacion(game);
	if (key == KEY_2)
		segunda_lose(game);
	if (key == KEY_3)
		tercera_won(game);
	return (0);
}

// int key_pull(int key, t_game *game)
// {
// 	if (key == KEY_ESC)
// 		exit(0);
// 	if (key == KEY_A)
// 		write(1, "A", 1);
// 	if (key == KEY_1)
// 	{
// 		write(1, "levantado uno\n", 14);
// 	}
// 	if (key == KEY_2)
// 		write(1, "levantado dos\n", 14);
// }

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
		if (type == 1)
			game->images.lose[i] = mlx_xpm_file_to_image(game->graphic.mlx, path, &w, &h);
		else if (type == 2)
			game->images.won[i] = mlx_xpm_file_to_image(game->graphic.mlx, path, &w, &h);
	free(path);
	}
}

void loops(t_game *game)
{
	int static i = 0;
	int static frame = 0;
	if (!(frame % 600))
	{
		if (game->type == 1)
		{
			mlx_put_image_to_window(game->graphic.mlx, game->graphic.win, game->images.lose[i], 0, 0);
			if (i == LOSE - 1)
				i = 0;
		}
		else if (game->type == 2)
		{
			mlx_put_image_to_window(game->graphic.mlx, game->graphic.win, game->images.won[i], 0, 0);

			if (i == WON - 1)
				i = 0;
		}
		i++;
		frame = 1;
	}
		else
		frame++;
}

void segunda_lose(t_game *game)
{
	game->type = 1;
	mlx_destroy_window(game->graphic.mlx, game->graphic.win);
	load_image(game, "lose", LOSE, 1);

	game->graphic.win = mlx_new_window(game->graphic.mlx, 854, 480, "You Lose");

	mlx_loop_hook(game->graphic.mlx, (void *)loops, game);
	mlx_hook(game->graphic.win, ON_KEYPRESS, 1L << 0, key_push, game);
}

void tercera_won(t_game *game)
{
	game->type = 2;
	mlx_destroy_window(game->graphic.mlx, game->graphic.win);
	load_image(game, "won", WON, 2);

	game->graphic.win = mlx_new_window(game->graphic.mlx, 854, 480, "You Won");
	// mlx_put_image_to_window(game->graphic.mlx, game->graphic.win, game->images.won[0], 0, 0);
	mlx_loop_hook(game->graphic.mlx, (void *)loops, game);
	mlx_hook(game->graphic.win, ON_KEYPRESS, 1L << 0, key_push, game);
}

void presentacion(t_game *game)
{

	if (game->graphic.win)
	{
		mlx_destroy_window(game->graphic.mlx, game->graphic.win);
		mlx_clear_window(game->graphic.mlx, game->graphic.win);
	}
	char *path_rabbit = "../xpm/bigmom_sm.xpm";
	int img_width;
	int img_height;
	game->graphic.win = mlx_new_window(game->graphic.mlx, 20 * 32, 15 * 32, "nach131 So Long");
	game->images.mom = mlx_xpm_file_to_image(game->graphic.mlx, path_rabbit, &img_width, &img_height);
	mlx_put_image_to_window(game->graphic.mlx, game->graphic.win, game->images.mom, 0, 0);
	mlx_hook(game->graphic.win, ON_DESTROY, 1L << 0, (void *)exit, game);
	mlx_hook(game->graphic.win, ON_KEYPRESS, 1L << 0, key_push, game);
	// mlx_hook(game->graphic.win, ON_KEYRELEASE, 1L << 0, key_pull, game);
}

int main(void)
{
	t_game game;

	ft_bzero(&game, sizeof(t_game));
	game.graphic.mlx = mlx_init();
	presentacion(&game);
	mlx_loop(game.graphic.mlx);
}

// gcc -framework OpenGL -framework AppKit main_dos_bis.c ../../../sources/mlx/libmlx.a
