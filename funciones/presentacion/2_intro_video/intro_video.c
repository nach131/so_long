/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro_video.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:55:59 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/02/13 11:02:49 by nmota-bu         ###   ########.fr       */
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

enum
{
	KEY_A = 0,
	KEY_1 = 18,
	KEY_2 = 19,
	KEY_3 = 20,
	KEY_ESC = 53,
};

#define LOSE 103
#define INTRO 149

typedef struct s_images
{
	void *mom;
	void *lose[LOSE];
	char *intro[INTRO];

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
void presentacion(t_game *game);

void key_push(int key, t_game *game)
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
		;
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
	if (type == 1)
		game->images.lose[i] = mlx_xpm_file_to_image(game->graphic.mlx, path, &w, &h);
	else if (type == 2)
		game->images.intro[i] = mlx_xpm_file_to_image(game->graphic.mlx, path, &w, &h);
	free(path);
	}
}

void loop_intro(t_game *game)
{
	int static i = 0;
	int static frame = 0;
	if (!(frame % 300))
	{
	mlx_put_image_to_window(game->graphic.mlx, game->graphic.win, game->images.intro[i], 0, 0);

	if (i == INTRO - 1)
		segunda_lose(game);

	i++;
	frame = 1;
	}
	else
		frame++;
}

void loop_lose(t_game *game)
{
	int static i = 0;
	int static frame = 0;
	if (!(frame % 600))
	{
		mlx_put_image_to_window(game->graphic.mlx, game->graphic.win, game->images.lose[i], 0, 0);
		if (i == LOSE - 1)
			i = 0;
		i++;
		frame = 1;
	}
	else
		frame++;
}

void segunda_lose(t_game *game)
{
	mlx_destroy_window(game->graphic.mlx, game->graphic.win);
	load_image(game, "lose", LOSE, 1);

	game->graphic.win = mlx_new_window(game->graphic.mlx, 854, 480, "You Lose");

	mlx_loop_hook(game->graphic.mlx, (void *)loop_lose, game);
	mlx_hook(game->graphic.win, ON_KEYPRESS, 1L << 0, (void *)key_push, game);
	mlx_hook(game->graphic.win, ON_DESTROY, 1L << 0, (void *)exit, game);
}

void presentacion(t_game *game)
{
	load_image(game, "intro", INTRO, 2);
	game->graphic.win = mlx_new_window(game->graphic.mlx, 854, 480, "You intro");
	mlx_loop_hook(game->graphic.mlx, (void *)loop_intro, game);
	mlx_hook(game->graphic.win, ON_DESTROY, 1L << 0, (void *)exit, game);
	mlx_hook(game->graphic.win, ON_KEYPRESS, 1L << 0, (void *)key_push, game);
}

int main(void)
{
	t_game game;

	ft_bzero(&game, sizeof(t_game));
	game.graphic.mlx = mlx_init();
	presentacion(&game);
	mlx_loop(game.graphic.mlx);
}

// gcc -framework OpenGL -framework AppKit intro_video.c ../../../sources/mlx/libmlx.a ../../../sources/libft/libft.a
