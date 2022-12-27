/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reload.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 18:29:37 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/27 14:30:57 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "so_long.h"
#include "../../mlx/mlx.h"
#include "images.h"

void pasada_dos(t_game *game, int x, int y, char ch)
{
	if (x != 0 || y != 0)
	{
		x *= SQUARE;
		y *= SQUARE;
	}
	if (ch == '0')
		mlx_put_image_to_window(game->grafic.mlx, game->grafic.win,
								game->images.hero[2], y, x);
}

void re_floor(t_game *game, int x, int y, char ch)
{
	x *= SQUARE;
	y *= SQUARE;
	if (ch == '0')
		mlx_put_image_to_window(game->grafic.mlx, game->grafic.win,
								game->images.floor[0], y, x);
}

int reload_loop(t_game *game)
{
	// ft_printf("reload ");
	lap_map(game, re_floor);

	return (0);
}
