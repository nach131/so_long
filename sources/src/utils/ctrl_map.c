/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 22:31:01 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/23 20:24:52 by nmota-bu         ###   ########.fr       */
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

int lap_map(t_game *game, char ch)
{
	int i;
	int j;
	int count = 0;

	i = 0;
	while (i < game->map.rows)
	{
		j = 0;
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] == ch)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void different_char(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (i < game->map.rows)
	{
		j = 0;
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] != '1' && game->map.map[i][j] != '0' && game->map.map[i][j] != 'C' && game->map.map[i][j] != 'E' && game->map.map[i][j] != 'X' && game->map.map[i][j] != 'P')
			{
				ft_message(WARNING, MSG_WAR_4);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

void control_map(t_game *game)
{
	game->map.rows = len_rows(game->map.map);
	len_cols(&game->map);
	if (lap_map(game, 'P') != 1)
	{
		ft_message(WARNING, MSG_WAR_1);
		exit(EXIT_FAILURE);
	}
	if (lap_map(game, 'E') != 1)
	{
		ft_message(WARNING, MSG_WAR_2);
		exit(EXIT_FAILURE);
	}
	game->map.objets.goals = lap_map(game, 'C');
	if (game->map.objets.goals == 0)
	{
		ft_message(WARNING, MSG_WAR_3);
		exit(EXIT_FAILURE);
	}
	different_char(game);
}
