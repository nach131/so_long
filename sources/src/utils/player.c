/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:40:59 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/30 23:58:37 by nmota-bu         ###   ########.fr       */
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
	}
	else if (ch == 'E')
	{
		game->map.objets.exit.x = x;
		game->map.objets.exit.y = y;
	}
}

void put_player(t_game *game, int type)
{
	mlx_put_image_to_window(game->grafic.mlx, game->grafic.win,
							game->images.floor[0],
							game->map.objets.player.y * SQUARE,
							game->map.objets.player.x * SQUARE + HEADER);
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
							game->map.objets.player.x * SQUARE + HEADER);
}

void open_door(t_game *game)
{
	int static finished = FALSE;

	if (!finished)

	{
		mlx_put_image_to_window(game->grafic.mlx, game->grafic.win,
								game->images.door[1],
								game->map.objets.exit.y * SQUARE,
								game->map.objets.exit.x * SQUARE + HEADER);
		finished = TRUE;
	}
}

void move(t_game *game, int x, int y, int type)
{
	if (game->map.map[x][y] == 'C')
		game->map.objets.get++;
	if (game->map.map[x][y] != '1' && game->map.map[x][y] != 'E')
	{
		game->map.map[x][y] = 'P';
		put_player(game, type);
		ctrl_move(game);
	}
	if (game->map.objets.goals == game->map.objets.get)
	{
		// ft_printf(MAGENTA "ya puedes salir melon");
		open_door(game);
	}

	if (game->map.map[x][y] == 'E' &&
		(game->map.objets.get == game->map.objets.goals))
		exit(0);
	// free_map(game);
	// ft_printf(RED "CONSEGUIDO");
}

// 2-124  D
// 0-123  A
// 1-125  S
// 13-126 W
