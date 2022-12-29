/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 12:13:23 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/16 19:18:44 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <../../../sources/mlx/mlx.h>
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
	char *logo[40];
	char **map;
} t_game;

#define ROWS 6

int ft_free_map(void *mlx, void *win)
{
	// mlx_destroy_window(mlx, win);

	exit(1);
	return (0);
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
	else if (keycode == 2)
	{
		// map[4][1] = '0';
		// map[4][2] = 'P';
		ft_printf(ORANGE "%c\n" WHITE, game->map[1][1]);
		game->map[4][1] = '0';
		game->map[1][1] = 'P';
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
	{
		mlx_put_image_to_window(game->mlx, game->win, game->textures[ROCKS], y, x);
		printf("x:%d, y:%d\n", x, y);
	}
	if (ch == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->textures[GRASS], y, x);
	if (ch == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->textures[PLAYER], y, x);
	if (ch == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->textures[DOORC], y, x);
	if (ch == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->logo[0], y, x);
}

void load_images(t_game *game)
{
	int width;
	int height;

	game->textures[ROCKS] = mlx_xpm_file_to_image(game->mlx, "../xpm/rocks.xpm", &width, &height);
	game->textures[TGREEN] = mlx_xpm_file_to_image(game->mlx, "../xpm/tree_GREEN.xpm", &width, &height);
	game->textures[GRASS] = mlx_xpm_file_to_image(game->mlx, "../xpm/central.xpm", &width, &height);
	game->textures[PLAYER] = mlx_xpm_file_to_image(game->mlx, "../xpm/frog_front.xpm", &width, &height);
	game->textures[DOORC] = mlx_xpm_file_to_image(game->mlx, "../xpm/door_closed.xpm", &width, &height);
	// game->textures[COL] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/3d/3d4.xpm", &width, &height);
	game->logo[0] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/3d/logo0.xpm", &width, &height);
	game->logo[1] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/3d/logo1.xpm", &width, &height);
	game->logo[2] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/3d/logo2.xpm", &width, &height);
	game->logo[3] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/3d/logo3.xpm", &width, &height);
	game->logo[4] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/3d/logo4.xpm", &width, &height);
	game->logo[5] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/3d/logo5.xpm", &width, &height);
	game->logo[6] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/3d/logo6.xpm", &width, &height);
	game->logo[7] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/3d/logo7.xpm", &width, &height);
	game->logo[8] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/3d/logo8.xpm", &width, &height);
	game->logo[9] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/3d/logo9.xpm", &width, &height);
	game->logo[10] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/3d/logo10.xpm", &width, &height);
	game->logo[11] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/3d/logo11.xpm", &width, &height);
	game->logo[12] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/3d/logo12.xpm", &width, &height);
	game->logo[13] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/3d/logo13.xpm", &width, &height);
	game->logo[14] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/3d/logo14.xpm", &width, &height);
	game->logo[15] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/3d/logo15.xpm", &width, &height);
	game->logo[16] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/3d/logo16.xpm", &width, &height);
	game->logo[17] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/3d/logo17.xpm", &width, &height);
	game->logo[18] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/3d/logo18.xpm", &width, &height);
	game->logo[19] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/3d/logo19.xpm", &width, &height);
	game->logo[20] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/3d/logo20.xpm", &width, &height);
	game->logo[21] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/3d/logo21.xpm", &width, &height);
	game->logo[22] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/3d/logo22.xpm", &width, &height);
	game->logo[23] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/3d/logo23.xpm", &width, &height);
	game->logo[24] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/3d/logo24.xpm", &width, &height);
	game->logo[25] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/3d/logo25.xpm", &width, &height);
	game->logo[26] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/3d/logo26.xpm", &width, &height);
	game->logo[27] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/3d/logo27.xpm", &width, &height);
	game->logo[28] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/3d/logo28.xpm", &width, &height);
	game->logo[29] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/3d/logo29.xpm", &width, &height);
	game->logo[30] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/3d/logo30.xpm", &width, &height);
	game->logo[31] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/3d/logo31.xpm", &width, &height);
	game->logo[32] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/3d/logo32.xpm", &width, &height);
	game->logo[33] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/3d/logo33.xpm", &width, &height);
	game->logo[34] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/3d/logo34.xpm", &width, &height);
	game->logo[35] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/3d/logo35.xpm", &width, &height);
	game->logo[36] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/3d/logo36.xpm", &width, &height);
	game->logo[37] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/3d/logo37.xpm", &width, &height);
	game->logo[38] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/3d/logo38.xpm", &width, &height);
	game->logo[39] = mlx_xpm_file_to_image(game->mlx, "../../../sources/xpm/3d/logo39.xpm", &width, &height);
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
	// mlx_string_put(game->mlx, game->win, 10, 12, 00001010, "toma");	  // NACH ESTO ES EL MARCADOR
	// mlx_string_put(game->mlx, game->win, 10, 22, 0xffffffff, "0/12"); // NACH ESTO ES EL MARCADOR
	mlx_hook(game->win, ON_DESTROY, 1L << 0, ft_free_map, game->mlx);
}

void put_logo(t_game *game, int x, int y)
{
	int w;
	int h;
	int static i;
	if (!i)
		i = 0;
	x *= 32;
	y *= 32;
	mlx_put_image_to_window(game->mlx, game->win, game->logo[i], y, x);
	usleep(40000);
	if (i == 38)
		i = 0;
	i++;
	// ft_printf(RED "\tloop" WHITE);
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
			if (game->map[i][j] == '0')
				put_grass(game, i, j);

			j++;
		}
		i++;
	}
}

void los_dos(t_game *game)
{
	windows(game);
	loop_logo(game);
}

int main(void)
{
	t_game game;
	ft_bzero(&game, sizeof(t_game));

	// char **map = ft_file_to_dptr("min.ber", 0);
	game.map = ft_file_to_dptr("min.ber", 0);

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 20 * 32, ROWS * 32, "nach131 So Long");
	load_images(&game);
	windows(&game);
	mlx_string_put(game.mlx, game.win, 10, 12, 00001010, "toma");	// NACH ESTO ES EL MARCADOR
	mlx_string_put(game.mlx, game.win, 10, 22, 0xffffffff, "0/12"); // NACH ESTO ES EL MARCADOR
	mlx_key_hook(game.win, key_hook, &game);
	mlx_loop_hook(game.mlx, los_dos, &game);
	// mlx_loop_hook(game.mlx, loop_logo, &game);
	mlx_loop(game.mlx);
}

// gcc -framework OpenGL -framework AppKit put_arr_img.c ../../../sources/mlx/libmlx.a ../../../sources/libft/libft.a
