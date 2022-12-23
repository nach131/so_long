/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 22:31:01 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/23 16:28:54 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "so_long.h"

int static len_rows(char **map)
{
	int i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void static len_cols(t_map *map)
{
	int i;

	if (!map->cols)
		map->cols = ft_strlen(map->map[0]);
	i = 1;
	while (i < map->rows)
	{
		if (map->cols != ft_strlen(map->map[i]))
		{
			ft_message(WARNING, MSG_WAR_0);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void static is_player_exit(t_game *game, int x, int y, char ch)
{
	(void)x;
	(void)y;
	(void)game;
	int static p = 0;
	int static e = 0;
	if (ch == 'P')
		p++;
	if (ch == 'E')
		e++;
	if (p >= 2 || e >= 2)
	{
		ft_message(WARNING, MSG_WAR_6);
		exit(EXIT_FAILURE);
	}
}

void lap_map(t_game *game, void (*function)(t_game *, int, int, char))
{
	int i;
	int j;

	i = 0;
	while (i < game->map.rows)
	{
		j = 0;
		while (game->map.map[i][j])
		{
			function(game, i, j, game->map.map[i][j]);
			j++;
		}
		i++;
	}
}

void control_map(t_game *game)
{
	game->map.rows = len_rows(game->map.map);
	len_cols(&game->map);
	lap_map(game, is_player_exit);
}
