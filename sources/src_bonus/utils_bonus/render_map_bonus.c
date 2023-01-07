/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 15:04:01 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/01/07 13:36:44 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "so_long_bonus.h"
#include "images_bonus.h"
#include "../../mlx/mlx.h"

int	random_num(int n)
{
	int	num;

	num = rand() % n;
	return (num);
}

//CAMBIR POR PUT_IMG
void static	put_gwall(t_game *game, int x, int y, int type)
{
	if (type == GWALL)
		mlx_put_image_to_window(game->grafic.mlx, game->grafic.win,
			game->images.gwall[random_num(7)], y, x);
}

// ESTA QUITAR
void static	put_wall(t_game *game, char *path, int x, int y)
{
	mlx_put_image_to_window(game->grafic.mlx, game->grafic.win, path, y, x);
}

void static	wall(t_game *game, int x, int y)
{
	int	h;
	int	v;

	h = (game->map.rows * SQUARE) - SQUARE;
	v = (game->map.cols * SQUARE) - SQUARE;
	if (x == 0 && y == 0)
		put_wall(game, game->images.wall[WALL_TL], x + HEADER, y);
	else if (x == h && y == v && x != 0 && y != 0)
		put_wall(game, game->images.wall[WALL_BR], x + HEADER, y);
	else if (y == v && x == 0)
		put_wall(game, game->images.wall[WALL_TR], x + HEADER, y);
	else if (x == h && y == 0)
		put_wall(game, game->images.wall[WALL_BL], x + HEADER, y);
	else if (x == h)
		put_wall(game, game->images.wall[WALL_BC], x + HEADER, y);
	else if (y == v)
		put_wall(game, game->images.wall[WALL_CR], x + HEADER, y);
	else if (y == 0)
		put_wall(game, game->images.wall[WALL_CL], x + HEADER, y);
	else if (x == 0)
		put_wall(game, game->images.wall[WALL_TC], x + HEADER, y);
	else
		put_gwall(game, x + HEADER, y, GWALL);
}

void	filter_wall(t_game *game, int x, int y, char ch)
{
	if (x != 0 || y != 0)
	{
		x *= SQUARE;
		y *= SQUARE;
	}
	if (ch == '1')
		wall(game, x, y);
	if (ch == '0')
		put_img(game, game->images.floor[0], y / SQUARE, x / SQUARE);
	if (ch == 'P')
		put_img(game, game->images.hero_d[0], y / SQUARE, x / SQUARE);
	if (ch == 'E')
		put_img(game, game->images.door[0], y / SQUARE, x / SQUARE);
	if (ch == 'C')
		put_img(game, game->images.logo[0], y / SQUARE, x / SQUARE);
}
