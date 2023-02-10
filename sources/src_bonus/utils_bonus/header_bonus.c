/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:29:45 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/02/11 00:31:27 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "so_long_bonus.h"
#include "images_bonus.h"
#include "../../mlx/mlx.h"

void	put_sea(t_game *game, int row)
{
	int	i;

	i = -1;
	while (++i < game->map.cols)
		mlx_put_image_to_window(game->graphic.mlx, game->graphic.win,
			game->images.header[0], i * SQUARE, row);
}

void	header(t_game *game)
{
	int	dst;

	dst = game->map.cols / 2 * SQUARE - 112;
	put_sea(game, 0);
	put_sea(game, SQUARE);
	if (game->map.cols < 16)
	{
		mlx_put_image_to_window(game->graphic.mlx,
			game->graphic.win, game->images.header[2], 32, 0);
	}
	else if (game->map.cols >= 16)
	{
		mlx_put_image_to_window(game->graphic.mlx, game->graphic.win,
			game->images.header[1], dst, 0);
		mlx_put_image_to_window(game->graphic.mlx, game->graphic.win,
			game->images.header[2], 32, 0);
	}
}
