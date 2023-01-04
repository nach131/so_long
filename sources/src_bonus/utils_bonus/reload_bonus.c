/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reload_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 18:29:37 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/01/04 23:08:27 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "so_long_bonus.h"
#include "../../mlx/mlx.h"
#include "images_bonus.h"

void filter_cero(t_game *game, int x, int y, char ch)
{
	x *= SQUARE;
	y *= SQUARE;
	if (ch == '0')
	{
		mlx_put_image_to_window(game->grafic.mlx, game->grafic.win,
								game->images.floor[0], y, x + HEADER);
		// mlx_put_image_to_window(game->grafic.mlx, game->grafic.win,
		// 						game->images.red[0], y, x + HEADER);
	}
}

void put_logo(t_game *game, int x, int y)
// void put_logo(t_game *game)
{
	int static i = 0;
	int static tomate = 0;

	x *= 32;
	y *= 32;

	// if (!(game->fps % 120))
	if (!(tomate % 200))
	{
		mlx_put_image_to_window(game->grafic.mlx,
								game->grafic.win, game->images.logo[i],
								y, x + HEADER);
		// mlx_put_image_to_window(game->grafic.mlx, game->grafic.win,
		// 						game->images.logo[i],
		// 						16 * SQUARE,
		// 						3 * SQUARE + HEADER);
		// mlx_put_image_to_window(game->grafic.mlx, game->grafic.win,
		// 						game->images.logo[i],
		// 						17 * SQUARE,
		// 						3 * SQUARE + HEADER);
		if (i == 38)
			i = 0;
		i++;
	}
	else
		tomate++;
}

void filter_colecc(t_game *game, int x, int y, char ch)
{
	if (ch == 'C')
		put_logo(game, x, y);
}

void loop_hero_next(t_game *game, int i)
{
	if (game->dir.down)
		mlx_put_image_to_window(game->grafic.mlx, game->grafic.win,
								game->images.hero_d[i],
								game->map.objets.player.y * SQUARE,
								game->map.objets.player.x * SQUARE + HEADER);
	else if (game->dir.up)
		mlx_put_image_to_window(game->grafic.mlx, game->grafic.win,
								game->images.hero_u[i],
								game->map.objets.player.y * SQUARE,
								game->map.objets.player.x * SQUARE + HEADER);
}

void loop_hero(t_game *game)
{
	int static i = 0;
	int static frame = 0;

	if (!(frame % 600))
	{
		if (game->dir.right)
			mlx_put_image_to_window(game->grafic.mlx, game->grafic.win,
									game->images.hero_r[i],
									game->map.objets.player.y * SQUARE,
									game->map.objets.player.x * SQUARE + HEADER);
		else if (game->dir.left)
			mlx_put_image_to_window(game->grafic.mlx, game->grafic.win,
									game->images.hero_l[i],
									game->map.objets.player.y * SQUARE,
									game->map.objets.player.x * SQUARE + HEADER);
		loop_hero_next(game, i);
		if (i == 7)
			i = 0;
		i++;
		frame = 1;
	}
	else
		frame++;
}
