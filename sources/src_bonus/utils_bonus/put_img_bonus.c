/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:35:14 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/01/14 11:55:43 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */
#include <stdlib.h>

#include "so_long_bonus.h"
#include "images_bonus.h"
#include "../mlx/mlx.h"

// CAMBIAR EL NOMBRE DEL ARCHIVO

void put_img(t_game *game, char *img, int y, int x)
{
	mlx_put_image_to_window(game->grafic.mlx, game->grafic.win,
							img, y * SQUARE, x * SQUARE + HEADER);
}

void put_mom(t_game *game)
{
	int static i = 0;

	put_img(game, game->images.mom[i], game->map.objets.enemy.y,
			game->map.objets.enemy.x);
	if (i == 3)
		i = 0;
	i++;
}

void put_hero_loop(t_game *game, char *img)
{
	mlx_put_image_to_window(game->grafic.mlx, game->grafic.win,
							img,
							game->map.objets.player.y * SQUARE,
							game->map.objets.player.x * SQUARE + HEADER);
}
