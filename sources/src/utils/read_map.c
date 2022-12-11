/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 15:04:01 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/11 15:24:39 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "so_long.h"
#include "images.h"
#include "mlx.h"

void static put_img(void *mlx, void *win, int x, int y, char *path)
{
	void *image;
	int img_width;
	int img_height;

	image = mlx_xpm_file_to_image(mlx, path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, image, y, x);
}

void filter_map(t_grafic grafic, int x, int y, char ch)
{

	if (x != 0 || y != 0)
	{
		x *= SQUARE;
		y *= SQUARE;
	}

	if (ch == '1')
	{
		put_img(grafic.mlx, grafic.win, x, y, TGREEN);
		printf("x:%d, y:%d\n", x, y);
	}
	if (ch == '0')
		put_img(grafic.mlx, grafic.win, x, y, GRASS);
	if (ch == 'P')
		put_img(grafic.mlx, grafic.win, x, y, FROG_F);
	if (ch == 'E')
		put_img(grafic.mlx, grafic.win, x, y, DOORC);
	if (ch == 'C')
		put_img(grafic.mlx, grafic.win, x, y, ICOL);
}
