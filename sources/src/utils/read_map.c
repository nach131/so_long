/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 15:04:01 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/11 18:32:00 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "so_long.h"
#include "images.h"
#include "mlx.h"

void put_img(void *mlx, void *win, int x, int y, char *path)
{
	void *image;
	int img_width;
	int img_height;

	image = mlx_xpm_file_to_image(mlx, path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, image, y, x);
}

void wall(t_game *game, int x, int y)
{

	int h = (game->map.rows * 32) - 32;
	int v = (game->map.cols * 32) - 32;
	ft_printf(RED "rows:%i,cols:%i " WHITE, h, v);

	if (x == 0 && y == 0)
		put_img(game->grafic.mlx, game->grafic.win, 0, 0, WELL_TL);
	else if (x == h && y == v && x != 0 && y != 0)
		put_img(game->grafic.mlx, game->grafic.win, x, y, WELL_BR);

	else if (x == 0)
		put_img(game->grafic.mlx, game->grafic.win, x, y, WELL_TC);

	printf("x:%d, y:%d\n", x, y);
}

void filter_map(t_game *game, int x, int y, char ch)
{

	if (x != 0 || y != 0)
	{
		x *= SQUARE;
		y *= SQUARE;
	}

	if (ch == '1')
	{
		// put_img(game->grafic.mlx, game->grafic.win, x, y, WELL_TC);
		// put_img(grafic.mlx, grafic.win, x, y, WELL_TL);
		// ft_printf("x:%d, y:%d\n", x, y);
		wall(game, x, y);
	}
	if (ch == '0')
		put_img(game->grafic.mlx, game->grafic.win, x, y, GRASS);
	if (ch == 'P')
		put_img(game->grafic.mlx, game->grafic.win, x, y, FROG_F);
	if (ch == 'E')
		put_img(game->grafic.mlx, game->grafic.win, x, y, GRASS);
	if (ch == 'C')
		put_img(game->grafic.mlx, game->grafic.win, x, y, ICOL);
}

