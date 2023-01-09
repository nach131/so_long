/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 15:04:01 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/01/09 23:44:42 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "so_long.h"
#include "images.h"
#include "../../mlx/mlx.h"

int random_num(int n)
{
	int num;

	num = rand() % n;
	return (num);
}

void static put_gwall(t_game *game, int x, int y, int type)
{
	if (type == GWALL)
		mlx_put_image_to_window(game->grafic.mlx,
								game->grafic.win,
								game->images.gwall[random_num(7)], y, x);
}

void static put_wall(t_game *game, char *path, int x, int y)
{
	mlx_put_image_to_window(game->grafic.mlx,
							game->grafic.win, path, y, x);
}

void static wall(t_game *game, int x, int y)
{
	int h;
	int v;

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
		mlx_put_image_to_window(game->grafic.mlx, game->grafic.win,
								game->images.floor[0], y, x + HEADER);
	if (ch == 'P')
		mlx_put_image_to_window(game->grafic.mlx, game->grafic.win,
								game->images.hero[0], y, x + HEADER);
	if (ch == 'E')
		mlx_put_image_to_window(game->grafic.mlx, game->grafic.win,
								game->images.door[0], y, x + HEADER);
	if (ch == 'C')
		mlx_put_image_to_window(game->grafic.mlx, game->grafic.win,
								game->images.logo[0], y, x + HEADER);
}
