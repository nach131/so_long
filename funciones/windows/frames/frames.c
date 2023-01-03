/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frames.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:09:45 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/01/03 11:15:31 by nmota-bu         ###   ########.fr       */
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

int render_loop(void *data)
{
	mlx_clear_window(mlx, win);
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_do_sync(mlx, 24);
	return (0);
}

int main(void)
{
	void *mlx;
	void *win;
	void *img;

	int width = 640;
	int height = 480;
	int bpp = 32;
	int size_l = width * bpp / 8;
	int endian = 0;

	mlx = mlx_init();
	win = mlx_new_window(mlx, width, height, "Mi ventana");
	img = mlx_new_image(mlx, width, height);

	void *data = mlx_get_data_addr(img, &bpp, &size_l, &endian);

	mlx_loop_hook(mlx, render_loop, data);
	mlx_loop(mlx);

	return (0);
}

// gcc -framework OpenGL -framework AppKit
