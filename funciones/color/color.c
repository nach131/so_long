/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:37:37 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/29 18:03:44 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "../../sources/mlx/mlx.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct s_data
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_data;

int key_hook(int keycode)
{
	// printf("Keycode: %d\n", keycode);
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
}

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	printf("%d\n", dst);
}

int main(void)
{
	void *mlx;
	void *win;
	t_data img;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 765, 480, "Hello world!");
	img.img = mlx_new_image(mlx, 765, 480);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);
	my_mlx_pixel_put(&img, 50, 50, 0x00FF00FF);
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);

	mlx_hook(win, 17, 1L << 0, (void *)exit, 0);
	mlx_key_hook(win, key_hook, 0);
	mlx_loop(mlx);
}

// gcc -framework OpenGL -framework AppKit
