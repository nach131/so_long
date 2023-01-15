/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:29:45 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/01/15 14:17:28 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "so_long.h"
#include "images.h"
#include "../../mlx/mlx.h"

void	put_sea(t_game *game, int row)
{
	int	i;

	i = -1;
	while (++i < game->map.cols)
		mlx_put_image_to_window(game->grafic.mlx,
			game->grafic.win, game->images.header[0], i * SQUARE, row);
}

void	header(t_game *game)
{
	int	dst;

	dst = game->map.cols / 2 * SQUARE - 112;
	put_sea(game, 0);
	put_sea(game, SQUARE);
	if (game->map.cols > 8)
	{
		mlx_put_image_to_window(game->grafic.mlx,
			game->grafic.win, game->images.header[1], dst, 0);
	}
}
