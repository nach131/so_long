/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:40:59 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/27 15:31:04 by nmota-bu         ###   ########.fr       */
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

// void move_w(t_game *game)
// {
// 	game->map.objets.player.x -= 1;
// 	mlx_put_image_to_window(game->grafic.mlx, game->grafic.win,
// 							game->images.hero[3],
// 							game->map.objets.player.y * SQUARE,
// 							game->map.objets.player.x * SQUARE);
// }

// void move_s(t_game *game)
// {
// 	ft_printf(RED "\tx%d, y%d\n",
// 			  game->map.objets.player.x, game->map.objets.player.y);

// 	// int x = game->map.objets.player.x;
// 	// int y = game->map.objets.player.y + 1;
// 	game->map.map[2][1] = '0';
// 	game->map.map[3][1] = 'P';
// 	game->map.objets.player.x += 1;
// 	mlx_put_image_to_window(game->grafic.mlx, game->grafic.win,
// 							game->images.hero[2],
// 							game->map.objets.player.y * SQUARE,
// 							game->map.objets.player.x * SQUARE);
// 	ft_printf(CYAN "\tx%d, y%d\n",
// 			  game->map.objets.player.x, game->map.objets.player.y);
// }

// void move_a(t_game *game)
// {
// 	game->map.objets.player.y -= 1;
// 	mlx_put_image_to_window(game->grafic.mlx, game->grafic.win,
// 							game->images.hero[1],
// 							game->map.objets.player.y * SQUARE,
// 							game->map.objets.player.x * SQUARE);
// }

// void move_d(t_game *game)
// {
// 	game->map.objets.player.y += 1;
// 	mlx_put_image_to_window(game->grafic.mlx, game->grafic.win,
// 							game->images.hero[0],
// 							game->map.objets.player.y * SQUARE,
// 							game->map.objets.player.x * SQUARE);
// }

void put_player(t_game *game, int type)
{
	mlx_put_image_to_window(game->grafic.mlx, game->grafic.win,
							game->images.hero[type],
							game->map.objets.player.y * SQUARE,
							game->map.objets.player.x * SQUARE);
}

void move(t_game *game, int key)
{
	// ft_printf(CYAN "\tx%d, y%d\n",
	// 		  game->map.objets.player.x, game->map.objets.player.y);
	game->map.map[game->map.objets.player.x][game->map.objets.player.y] = '0';
	if (key == 1 || key == 125) // S
	{
		game->map.map[game->map.objets.player.x + 1][game->map.objets.player.y] = 'P';
		game->map.objets.player.x += 1;
		put_player(game, 2);
	}
	if (key == 13 || key == 126) // W
	{
		game->map.map[game->map.objets.player.x - 1][game->map.objets.player.y] = 'P';
		game->map.objets.player.x -= 1;
		put_player(game, 3);
	}
	if (key == 0 || key == 123) // A
	{
		game->map.map[game->map.objets.player.x][game->map.objets.player.y - 1] = 'P';
		game->map.objets.player.y -= 1;
		put_player(game, 1);
	}
	if (key == 2 || key == 124) // D
	{
		game->map.map[game->map.objets.player.x][game->map.objets.player.y + 1] = 'P';
		game->map.objets.player.y += 1;
		put_player(game, 0);
	}
}
