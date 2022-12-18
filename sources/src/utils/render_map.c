/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 15:04:01 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/18 12:33:50 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "so_long.h"
#include "images.h"
#include "../../mlx/mlx.h"

void static put_img(t_game *game, int x, int y, char *path)
{
	int img_width;
	int img_height;

	// ESTO PARA CARGAR LA IMAGEN EN EL JUEGO
	game->grafic.img = mlx_xpm_file_to_image(game->grafic.mlx,
											 path, &img_width, &img_height);

	// AQUI PARA PONER LA IMGEN EN EL MAPA
	mlx_put_image_to_window(game->grafic.mlx,
							game->grafic.win, game->grafic.img, y, x);
}

int random_num(int n)
{
	int num;

	num = rand() % n;
	return (num);
}

void static put_gwall(t_game *game, int x, int y, int type)
{
	if (type == 0)
		mlx_put_image_to_window(game->grafic.mlx,
								game->grafic.win,
								game->images.gwall[random_num(7)], y, x);
	// if (type == 1)
	// 	mlx_put_image_to_window(game->grafic.mlx,
	// 							game->grafic.win,
	// 							game->images.floor[random_num(7)], y, x);
}

void static wall(t_game *game, int x, int y)
{
	int h;
	int v;

	h = (game->map.rows * 32) - 32;
	v = (game->map.cols * 32) - 32;
	if (x == 0 && y == 0)
		put_img(game, 0, 0, WELL_TL);
	else if (x == h && y == v && x != 0 && y != 0)
		put_img(game, x, y, WELL_BR);
	else if (y == v && x == 0)
		put_img(game, x, y, WELL_TR);
	else if (x == h && y == 0)
		put_img(game, x, y, WELL_BL);
	else if (x == h)
		put_img(game, x, y, WELL_BC);
	else if (y == v)
		put_img(game, x, y, WELL_CR);
	else if (y == 0)
		put_img(game, x, y, WELL_CL);
	else if (x == 0)
		put_img(game, x, y, WELL_TC);
	else
		put_gwall(game, x, y, GWALL);
}

void filter_map(t_game *game, int x, int y, char ch)
{
	if (x != 0 || y != 0)
	{
		x *= SQUARE;
		y *= SQUARE;
	}
	if (ch == '1')
		wall(game, x, y);
	if (ch == '0')
		mlx_put_image_to_window(game->grafic.mlx,
								game->grafic.win,
								game->images.floor[0], y, x);
	if (ch == 'P')
		put_img(game, x, y, FROG_F);
	if (ch == 'E')
		put_img(game, x, y, DOORC);
	if (ch == 'C')
		put_img(game, x, y, ICOL);
}
