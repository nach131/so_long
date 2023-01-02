/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reload_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 18:29:37 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/01/02 21:08:42 by nmota-bu         ###   ########.fr       */
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
	if (x != 0 || y != 0)
	{
		x *= SQUARE;
		y *= SQUARE;
	}
	if (ch == '0')
		mlx_put_image_to_window(game->grafic.mlx, game->grafic.win,
								game->images.red[0], y, x + HEADER);
	// if (ch == 'P')
	// 	mlx_put_image_to_window(game->grafic.mlx, game->grafic.win,
	// 							game->images.hero[0], y, x + HEADER);

	// if (ch == 'C')
	// 	mlx_put_image_to_window(game->grafic.mlx, game->grafic.win,
	// 							game->images.logo[0], y, x + HEADER);
	// if (ch == 'X')
	// 	mlx_put_image_to_window(game->grafic.mlx, game->grafic.win,
	// 							game->images.mom[0], y, x + HEADER);
}

void put_logo(t_game *game, int x, int y)
{
	int static i = 0;

	x *= 32;
	y *= 32;

	if (!(game->fps % 45))
	{
		mlx_put_image_to_window(game->grafic.mlx,
								game->grafic.win, game->images.logo[i],
								y, x + HEADER);
		if (i == 38)
			i = 0;
		i++;
	}
}

void loop_hero(t_game *game)
{
	int static i = 0;

	if (!(game->fps % 100))
	{
		mlx_put_image_to_window(game->grafic.mlx, game->grafic.win,
								game->images.hero[i],
								game->map.objets.player.y * SQUARE,
								game->map.objets.player.x * SQUARE + HEADER);
		if (i == 7)
			i = 0;
		i++;
	}
}

void filter_colecc(t_game *game, int x, int y, char ch)
{
	if (ch == 'C')
		put_logo(game, x, y);
	// 	mlx_put_image_to_window(game->grafic.mlx, game->grafic.win,
	// 							game->images.logo[0], y, x + HEADER);
	// if (ch == 'X')
	// 	mlx_put_image_to_window(game->grafic.mlx, game->grafic.win,
	// 							game->images.mom[0], y, x + HEADER);
}

int reload(t_game *game)
{
	// printf(GREEN "%d ", game->reload);
	game->fps++;
	loop_hero(game);
	lap_map(game, filter_colecc);
	if (!game->reload)
	{
		printf(RED "RELOAD ");
		lap_map(game, filter_cero);
		game->reload = TRUE;
	}

	return (0);
}
