/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_move_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:49:52 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/30 16:30:11 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "so_long_bonus.h"
#include "../mlx/mlx.h"

void ctrl_move(t_game *game)
{
	int i;
	char *total;

	total = ft_itoa(game->map.objets.goals);
	game->map.objets.move++;
	ft_printf(ORANGE "Movements: %d" WHITE, game->map.objets.move);
	game->map.objets.movements = ft_itoa(game->map.objets.move);
	i = -1;
	while (++i < (ft_strlen(game->map.objets.movements) + 11))
		write(1, "\b", 1);
	// mlx_string_put(game->grafic.mlx, game->grafic.win, 80, 30, 0xFFFFFFFF,
	// 			   game->map.objets.movements);									   // NACH ESTO ES EL MARCADOR
	// mlx_string_put(game->grafic.mlx, game->grafic.win, 80, 55, 0xffffffff, total); // NACH ESTO ES EL MARCADOR

	free(total);
	free(game->map.objets.movements);
}
