/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:51:19 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/18 14:14:24 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "so_long.h"

void position(t_scp *pos, int x, int y)
{
	pos->x = x;
	pos->y = y;
}

void ctrl_obj(t_objs *objets)
{
	if (objets->player.x == 0 && objets->player.y == 0)
	{
		ft_message(WARNING, MSG_WAR_2);
		exit(EXIT_FAILURE);
	}
	if (objets->exit.x == 0 && objets->exit.y == 0)
	{
		ft_message(WARNING, MSG_WAR_3);
		exit(EXIT_FAILURE);
	}
	if (objets->goals == 0)
	{
		ft_message(WARNING, MSG_WAR_4);
		exit(EXIT_FAILURE);
	}
}

int ctrl_wall(t_map map, int rows, int cols, char ch)
{
	int h = map.rows - 1;
	int v = map.cols - 1;

	if ((rows == 0 && cols <= v) && ch != '1')
		ft_printf(GREEN "\trow:%d col:%d\n" WHITE, rows, cols);
	else if ((rows > 0 && cols == 0) && ch != '1')
		ft_printf(GREEN "\trow:%d col:%d\n" WHITE, rows, cols);
	else if ((rows > 0 && cols == v) && ch != '1')
		ft_printf(GREEN "\trow:%d col:%d\n" WHITE, rows, cols);
	else if ((rows == h && cols <= v) && ch != '1')
		ft_printf(GREEN "\trow:%d col:%d\n" WHITE, rows, cols);
	else
		return (0);
	return (1);
}

void read_map(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (i < game->map.rows)
	{
		j = 0;
		while (game->map.map[i][j])
		{
			if (ctrl_wall(game->map, i, j, game->map.map[i][j]))
			{
				ft_message(WARNING, MSG_WAR_5);
				exit(EXIT_FAILURE);
			}
			if (game->map.map[i][j] == 'C')
				game->map.objets.goals += 1;
			else if (game->map.map[i][j] == 'P')
				position(&game->map.objets.player, i, j);
			else if (game->map.map[i][j] == 'E')
				position(&game->map.objets.exit, i, j);
			j++;
		}
		i++;
	}
	ctrl_obj(&game->map.objets);
}
