/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_move_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:49:52 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/30 23:35:28 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "so_long_bonus.h"
#include "../mlx/mlx.h"

char *collections(t_objs colec)
{
	char *total;
	char *get;
	char *s1;
	char *s2;

	total = ft_itoa(colec.goals);
	get = ft_itoa(colec.get);
	s1 = ft_strjoin(total, "/");
	s2 = ft_strjoin(s1, get);
	free(s1);
	return (s2);
}

void ctrl_move(t_game *game)
{
	int i;
	char *marcador;
	char *activity;

	marcador = collections(game->map.objets);
	// ft_printf(RED "\t%s\n", marcador);

	game->map.objets.move++;
	activity = ft_itoa(game->map.objets.move);
	i = -1;

	mlx_put_image_to_window(game->grafic.mlx, game->grafic.win,
							game->images.header[3], 75, 43);
	// NACH ESTO ES EL MARCADOR
	mlx_string_put(game->grafic.mlx, game->grafic.win, 119, 55, 0xFFFFFFFF, activity);
	mlx_string_put(game->grafic.mlx, game->grafic.win, 80, 55, 0xffffffff, marcador);

	free(marcador);
	free(activity);
}
