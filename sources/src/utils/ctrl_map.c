/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 22:31:01 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/22 23:12:02 by nmota-bu         ###   ########.fr       */
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

void control_map(t_game *game)
{
	game->map.rows = len_rows(game->map.map);
	len_cols(&game->map);
}
