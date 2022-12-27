/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:40:59 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/27 16:34:46 by nmota-bu         ###   ########.fr       */
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
		// ft_printf(RED "\tx:%d, y:%d char:%c\n", x, y, ch);
		ft_printf(RED "\tchar:%c\n", game->map.map[x][y]);
	}
	if (ch == 'E')
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

void move_bis(t_game *game, int key, int x, int y)
{
	if (key == 1 || key == 125)
	{
		if (game->map.map[x + 1][y] != '1')
		{
			game->map.map[x + 1][y] = 'P';
			put_player(game, 2);
		};
	}
	else if (key == 13 || key == 126)
	{
		if (game->map.map[x - 1][y] != '1')
		{
			game->map.map[x - 1][y] = 'P';
			put_player(game, 3);
		}
	}
}

void move(t_game *game, int key)
{
	int x = game->map.objets.player.x;
	int y = game->map.objets.player.y;

	game->map.map[x][y] = '0';
	if (key == 2 || key == 124)
	{
		if (game->map.map[x][y + 1] != '1')
		{
			game->map.map[x][y + 1] = 'P';
			put_player(game, 0);
		}
	}
	else if (key == 0 || key == 123)
	{
		if (game->map.map[x][y - 1] != '1')
		{
			game->map.map[x][y - 1] = 'P';
			put_player(game, 1);
		}
	}
	move_bis(game, key, x, y);
	// else if (key == 1 || key == 125)
	// {
	// 	if (game->map.map[x + 1][y] != '1')
	// 	{
	// 		game->map.map[x + 1][y] = 'P';
	// 		put_player(game, 2);
	// 	};
	// }
	// else if (key == 13 || key == 126)
	// {
	// 	if (game->map.map[x - 1][y] != '1')
	// 	{
	// 		game->map.map[x - 1][y] = 'P';
	// 		put_player(game, 3);
	// 	}
	// }
}

// 2-124  D
// 0-123  A
// 1-125  S
// 13-126 W
