/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:02:05 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/01/07 19:06:16 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "so_long_bonus.h"
#include "../../mlx/mlx.h"

void all_free(t_game *game)
{
	mlx_destroy_image(game->grafic.mlx, game->images.door[0]);
	// mlx_destroy_window(game->grafic.mlx, game->grafic.win);
	// mlx_clear_window(game->grafic.mlx, game->grafic.win);
}

void caught(t_game *game)
{
	char **map = game->map.map;
	int x = game->map.objets.enemy.x;
	int y = game->map.objets.enemy.y;

	if (map[x][y + 1] == 'P' || map[x][y - 1] == 'P' || map[x + 1][y] == 'P' || map[x - 1][y] == 'P')
	{
		ft_printf(RED "\tPILLADO\n");
		all_free(game);
		exit(0);
	}
}
