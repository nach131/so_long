/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:40:59 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/27 17:37:27 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "so_long.h"
#include "../mlx/mlx.h"

void locate(t_game *game, int x, int y, char ch)
{
	if (ch == 'P')
	{
		game->map.objets.player.x = x;
		game->map.objets.player.y = y;
		ft_printf(RED "\tchar:%c\n", game->map.map[x][y]);
	}
}

void put_player(t_game *game, int type)
{
	mlx_put_image_to_window(game->grafic.mlx, game->grafic.win,
							game->images.floor[0],
							game->map.objets.player.y * SQUARE,
							game->map.objets.player.x * SQUARE);
	if (type == 0)
		game->map.objets.player.y += 1;
	else if (type == 1)
		game->map.objets.player.y -= 1;
	else if (type == 2)
		game->map.objets.player.x += 1;
	else if (type == 3)
		game->map.objets.player.x -= 1;
	mlx_put_image_to_window(game->grafic.mlx, game->grafic.win,
							game->images.hero[type],
							game->map.objets.player.y * SQUARE,
							game->map.objets.player.x * SQUARE);
}

void move(t_game *game, int x, int y, int type)
{
	if (game->map.map[x][y] == 'C')
		game->map.objets.get++;
	if (game->map.map[x][y] != '1' && game->map.map[x][y] != 'E')
	{
		game->map.map[x][y] = 'P';
		put_player(game, type);
	}
	if (game->map.map[x][y] == 'E' &&
		(game->map.objets.get == game->map.objets.goals))
		exit(0);
	// ft_printf(RED "CONSEGUIDO");
}

// 2-124  D
// 0-123  A
// 1-125  S
// 13-126 W
