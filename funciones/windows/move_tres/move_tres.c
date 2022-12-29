/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tres.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:04:31 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/29 16:40:56 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "../../../sources/mlx/mlx.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../../sources/libft/inc/libft.h"
#include "../../../sources/libft/inc/ft_printf.h"
#include "../../../sources/libft/inc/colors.h"

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
	ROCKS,
	GRASS,
	TGREEN,
	DOORC,
	COL,
	PLAYER,
};

typedef struct s_game
{
	void *mlx;
	void *win;
	char *textures[6];
	char *hero[4];
	char *logo[40];
	char *mom[4];
	char **map;
} t_game;

#define ROWS 6

int ft_free_map(void *mlx, void *win)
{
	// mlx_destroy_window(mlx, win);

	exit(1);
	return (0);
}

void move_r(t_game *game)
{
	int i = -1;

	mlx_put_image_to_window(game->mlx, game->win, game->hero[1], 1 * 40, 4 * 32);

	mlx_put_image_to_window(game->mlx, game->win, game->hero[2], 1 * 48, 4 * 32);

	mlx_put_image_to_window(game->mlx, game->win, game->hero[3], 1 * 56, 4 * 32);
}

void move_l(t_game *game)
{
	int i = -1;

	mlx_put_image_to_window(game->mlx, game->win, game->hero[1], 1 * 56, 4 * 32);

	mlx_put_image_to_window(game->mlx, game->win, game->hero[2], 1 * 48, 4 * 32);

	mlx_put_image_to_window(game->mlx, game->win, game->hero[3], 1 * 40, 4 * 32);
}
// int key_hook(int keycode, char *map[], t_game *game)
int key_hook(int keycode, t_game *game)
{
	printf("Keycode: %d\n", keycode);
	if (keycode == 53)
		exit(0);
	else if (keycode == 13) // W
	{
		;
		// map[4][1] = '0';
		// map[4][2] = 'P';
		// mlx_put_image_to_window(mlx, win, textures[GRASS], 4, 2, logo);
		// mlx_put_image_to_window(mlx, win, textures[GRASS], 4, 2);
	}
	else if (keycode == 2) // D
	{
		ft_printf(ORANGE "%c\n" WHITE, game->map[4][1]);
		game->map[4][1] = '0';
		game->map[4][2] = 'P';
		move_r(game);
	}
	else if (keycode == 0) // A
	{
		ft_printf(ORANGE "%c\n" WHITE, game->map[4][2]);
		game->map[4][2] = '0';
		game->map[4][1] = 'P';
		move_l(game);
	}
	else if (keycode == 1)
		;
	return (0);
}

void filter(t_game *game, int x, int y, char ch)
{
	void *img_frog;
	int img_width;
	int img_height;
	// int number = rand() % 4;

	if (x != 0 || y != 0)
	{
		x *= 32;
		y *= 32;
	}

	if (ch == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->textures[ROCKS], y, x);
	if (ch == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->textures[GRASS], y, x);
	if (ch == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->hero[0], y, x);
	// if (ch == 'C')
	// 	mlx_put_image_to_window(game->mlx, game->win, game->logo[0], y, x);
	if (ch == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->mom[0], y, x);
}

void load_images(t_game *game)
{
	int width;
	int height;

	game->textures[ROCKS] = mlx_xpm_file_to_image(game->mlx, "../xpm/rocks.xpm", &width, &height);
	game->textures[TGREEN] = mlx_xpm_file_to_image(game->mlx, "../xpm/tree_GREEN.xpm", &width, &height);
	game->textures[GRASS] = mlx_xpm_file_to_image(game->mlx, "../xpm/central.xpm", &width, &height);
	game->textures[DOORC] = mlx_xpm_file_to_image(game->mlx, "../xpm/door_closed.xpm", &width, &height);
	game->logo[0] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo0.xpm", &width, &height);
	game->logo[1] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo1.xpm", &width, &height);
	game->logo[2] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo2.xpm", &width, &height);
	game->logo[3] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo3.xpm", &width, &height);
	game->logo[4] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo4.xpm", &width, &height);
	game->logo[5] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo5.xpm", &width, &height);
	game->logo[6] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo6.xpm", &width, &height);
	game->logo[7] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo7.xpm", &width, &height);
	game->logo[8] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo8.xpm", &width, &height);
	game->logo[9] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo9.xpm", &width, &height);
	game->logo[10] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo10.xpm", &width, &height);
	game->logo[11] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo11.xpm", &width, &height);
	game->logo[12] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo12.xpm", &width, &height);
	game->logo[13] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo13.xpm", &width, &height);
	game->logo[14] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo14.xpm", &width, &height);
	game->logo[15] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo15.xpm", &width, &height);
	game->logo[16] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo16.xpm", &width, &height);
	game->logo[17] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo17.xpm", &width, &height);
	game->logo[18] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo18.xpm", &width, &height);
	game->logo[19] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo19.xpm", &width, &height);
	game->logo[20] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo20.xpm", &width, &height);
	game->logo[21] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo21.xpm", &width, &height);
	game->logo[22] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo22.xpm", &width, &height);
	game->logo[23] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo23.xpm", &width, &height);
	game->logo[24] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo24.xpm", &width, &height);
	game->logo[25] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo25.xpm", &width, &height);
	game->logo[26] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo26.xpm", &width, &height);
	game->logo[27] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo27.xpm", &width, &height);
	game->logo[28] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo28.xpm", &width, &height);
	game->logo[29] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo29.xpm", &width, &height);
	game->logo[30] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo30.xpm", &width, &height);
	game->logo[31] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo31.xpm", &width, &height);
	game->logo[32] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo32.xpm", &width, &height);
	game->logo[33] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo33.xpm", &width, &height);
	game->logo[34] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo34.xpm", &width, &height);
	game->logo[35] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo35.xpm", &width, &height);
	game->logo[36] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo36.xpm", &width, &height);
	game->logo[37] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo37.xpm", &width, &height);
	game->logo[38] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo38.xpm", &width, &height);
	game->logo[39] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/logo/logo39.xpm", &width, &height);
	game->hero[0] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/frog/move_r/frog0.xpm", &width, &height);
	game->hero[1] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/frog/move_r/frog1.xpm", &width, &height);
	game->hero[2] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/frog/move_r/frog2.xpm", &width, &height);
	game->hero[3] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/frog/move_r/frog3.xpm", &width, &height);
	game->mom[0] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/mom/mom0.xpm", &width, &height);
	game->mom[1] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/mom/mom1.xpm", &width, &height);
	game->mom[2] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/mom/mom2.xpm", &width, &height);
	game->mom[3] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/mom/mom3.xpm", &width, &height);
}

void windows(t_game *game)
{
	int i = 0;
	int j;

	while (i < ROWS)
	{
		j = 0;
		while (game->map[i][j])
		{
			filter(game, i, j, game->map[i][j]);
			j++;
		}
		i++;
	}
	mlx_hook(game->win, ON_DESTROY, 1L << 0, ft_free_map, game->mlx);
}

void put_logo(t_game *game, int x, int y)
{
	int static i;
	int static fps = 0;

	if (!i)
		i = 0;
	x *= 32;
	y *= 32;

	if (!(fps % 25))
	{
		mlx_put_image_to_window(game->mlx, game->win, game->logo[i], y, x);
		if (i == 38)
			i = 0;
		i++;
		fps = 1;
	}
	else
	{
		fps++;
	}
}

void put_hero(t_game *game, int x, int y)
{
	int static i;
	int static fps = 0;

	if (!i)
		i = 0;
	x *= 32;
	y *= 32;

	if (!(fps % 25))
	{
		mlx_put_image_to_window(game->mlx, game->win, game->hero[i], y, x);
		if (i == 3)
			i = 0;
		i++;
		fps = 1;
	}
	else
	{
		fps++;
	}
}

void put_grass(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->textures[GRASS], y * 32, x * 32);
}

void loop_logo(t_game *game)
{
	int i = 0;
	int j;

	while (i < ROWS)
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				put_logo(game, i, j);
			else if (game->map[i][j] == 'P')
				put_hero(game, i, j);
			j++;
		}
		i++;
	}
}

void loop_hero(t_game *game)
{
	int i = 0;
	int j;
	int static fps = 0;
	int static p;

	if (!p)
		i = 0;

	while (i < ROWS)
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			// put_hero(game, i, j);
			{
				// mlx_put_image_to_window(game->mlx, game->win, game->textures[GRASS], j * 32, i * 32);

				if (!(fps % 25))
				{
					mlx_put_image_to_window(game->mlx, game->win, game->hero[p], j * 32, i * 32);
					if (p == 3)
						p = 0;
					p++;
					fps = 1;
				}
				else
				{
					fps++;
				}
			}

			if (game->map[i][j] == '0')
				put_grass(game, i, j);
			j++;
		}
		i++;
	}
}

void loop_mom(t_game *game)
{
	int w;
	int h;
	int static i;
	int static fps = 0;

	if (!i)
		i = 0;
	// x *= 32;
	// y *= 32;

	if (!(fps % 25))
	{
		mlx_put_image_to_window(game->mlx, game->win, game->mom[i], 0, 0);
		if (i == 4)
			i = 0;
		i++;
		fps = 1;
	}
	else
	{
		fps++;
	}
}

int los_dos(t_game *game)
{
	// windows(game);
	loop_logo(game);
	loop_mom(game);
	// loop_hero(game);
	return (0);
}

int main(void)
{
	t_game game;
	ft_bzero(&game, sizeof(t_game));
	game.map = ft_file_to_dptr("min.ber", 0);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 20 * 32, ROWS * 32, "nach131 So Long");
	load_images(&game);

	windows(&game);

	// mlx_put_image_to_window(game.mlx, game.win, game.mom[1], 64, 64);

	mlx_string_put(game.mlx, game.win, 10, 12, 00001010, "TRES");	// NACH ESTO ES EL MARCADOR
	mlx_string_put(game.mlx, game.win, 10, 22, 0xffffffff, "0/12"); // NACH ESTO ES EL MARCADOR
	mlx_key_hook(game.win, key_hook, &game);
	mlx_loop_hook(game.mlx, los_dos, &game);

	//===========================================================================================
	// mlx_expose_hook(game.win, loop_mom, &game);
	// mlx_loop_hook(game.mlx, loop_hero, &game);

	mlx_loop(game.mlx);
}

// gcc -framework OpenGL -framework AppKit move_tres.c  ../../../sources/mlx/libmlx.a ../../../sources/libft/libft.a

// ESTUDIAR CLEAR DE MLX
