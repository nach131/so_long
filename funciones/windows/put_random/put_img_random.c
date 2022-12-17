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

#include <mlx.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

#define ROWS 6

int ft_free_map(void *mlx, void *win)
{
	// mlx_destroy_window(mlx, win);

	exit(1);
	return (0);
}

int key_hook(int keycode, char *map[], char *textures, void *win, void *mlx)
{
	printf("Keycode: %d\n", keycode);
	if (keycode == 53)
		exit(0);
	else if (keycode == 13) // W
	{
		// map[4][1] = '0';
		// map[4][2] = 'P';
		mlx_put_image_to_window(mlx, win, textures[GRASS], 4, 2);
		// mlx_put_image_to_window(mlx, win, textures[GRASS], 4, 2);
	}
	else if (keycode == 0)
		;
	else if (keycode == 1)
		;
	return (0);
}

void filter(void *mlx, void *win, int x, int y, char ch, char **images)
{
	void *img_frog;
	int img_width;
	int img_height;
	int number = rand() % 5;

	if (x != 0 || y != 0)
	{
		x *= 32;
		y *= 32;
	}

	if (ch == '1')
	{
		mlx_put_image_to_window(mlx, win, images[number], y, x);
		printf("x:%d, y:%d\n", x, y);
	}
	if (ch == '0')
		mlx_put_image_to_window(mlx, win, images[GRASS], y, x);
	if (ch == 'P')
		mlx_put_image_to_window(mlx, win, images[PLAYER], y, x);
	if (ch == 'E')
		mlx_put_image_to_window(mlx, win, images[DOORC], y, x);
	if (ch == 'C')
		mlx_put_image_to_window(mlx, win, images[COL], y, x);
}

void load_images(void *mlx, char **textures)
{
	int width;
	int height;

	textures[ROCKS] = mlx_xpm_file_to_image(mlx, "../xpm/rocks.xpm", &width, &height);
	textures[TGREEN] = mlx_xpm_file_to_image(mlx, "../xpm/tree_GREEN.xpm", &width, &height);
	textures[GRASS] = mlx_xpm_file_to_image(mlx, "../xpm/central.xpm", &width, &height);
	textures[PLAYER] = mlx_xpm_file_to_image(mlx, "../xpm/frog_front.xpm", &width, &height);
	textures[DOORC] = mlx_xpm_file_to_image(mlx, "../xpm/door_closed.xpm", &width, &height);
	textures[COL] = mlx_xpm_file_to_image(mlx, "../xpm/3d_1.xpm", &width, &height);
}

void windows(void *mlx, void *win, char *images[], char *arr[])
{
	int i = 0;
	int j;

	// void *win;
	// win = mlx_new_window(mlx, 20 * 32, ROWS * 32, "nach131 So Long");
	while (i < ROWS)
	{
		j = 0;
		while (arr[i][j])
		{
			filter(mlx, win, i, j, arr[i][j], images);
			j++;
		}
		i++;
	}
	mlx_string_put(mlx, win, 20, 25, 11001101, "toma"); // NACH ESTO ES EL MARCADOR
	mlx_hook(win, ON_DESTROY, 1L << 0, ft_free_map, mlx);
}

int main(void)
{

	void *mlx;
	void *win;
	char *textures[5];

	char *map[] = {"11111111111111111111",
				   "100000001000000000C1",
				   "10010000011100000001",
				   "10000000000000000001",
				   "1P0000110E0000000001",
				   "11111111111111111111"};

	mlx = mlx_init();
	win = mlx_new_window(mlx, 20 * 32, ROWS * 32, "nach131 So Long");
	// load_images(mlx, (char **)&textures);
	load_images(mlx, textures);
	windows(mlx, win, textures, map);
	mlx_key_hook(win, key_hook, map);
	mlx_loop(mlx);
}

// gcc -framework OpenGL -framework AppKit put_arr_img.c ../../../sources/mlx/libmlx.a
