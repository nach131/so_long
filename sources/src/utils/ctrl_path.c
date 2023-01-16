/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:33:11 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/01/16 20:22:53 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "so_long.h"
#include <stdbool.h>

bool **collected;

void static find_path(t_game *game, int row, int col)
{
	int rows;
	int cols;
	char **arr;

	rows = game->map.rows;
	cols = game->map.cols;
	arr = game->map.tmp;
	if (row < 0 || row >= rows || col < 0 || col >= cols || arr[row][col] == '1' || arr[row][col] == '@')
		return;
	if (arr[row][col] == 'E')
		return;
	if (arr[row][col] == 'C' && !collected[row][col])
		collected[row][col] = true;
	arr[row][col] = '@';
	find_path(game, row - 1, col);
	find_path(game, row, col + 1);
	find_path(game, row + 1, col);
	find_path(game, row, col - 1);
}

void print_map(t_game *game)
{
	system("clear");
	for (int i = 0; i < game->map.rows; i++)
	{
		for (int j = 0; j < game->map.cols; j++)
		{
			ft_printf("%c", game->map.tmp[i][j]);
		}
		ft_printf("\n");
	}
}
void static err_exit(t_game *game, int x, int y)
{

	if (game->map.tmp[x - 1][y] != '@' && game->map.tmp[x + 1][y] != '@' && game->map.tmp[x][y + 1] != '@' && game->map.tmp[x][y - 1] != '@')
	{
		ft_message(WARNING, MSG_WAR_6);
		exit(EXIT_FAILURE);
	}
}
void static err_path(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (i < game->map.rows)
	{
		j = 0;
		while (j < game->map.cols)
		{
			if (game->map.tmp[i][j] == 'C')
			{
				ft_message(WARNING, MSG_WAR_6);
				exit(EXIT_FAILURE);
			}
			if (game->map.tmp[i][j] == 'E')
				err_exit(game, i, j);
			j++;
		}
		i++;
	}
}

void ctrl_path(t_game *game)
{
	int i;
	int j;

	collected = (bool **)ft_calloc(game->map.rows + 1, sizeof(bool *));
	i = 0;
	while (i < game->map.rows)
	{
		collected[i] = (bool *)ft_calloc(game->map.cols + 1, sizeof(bool *));
		i++;
	}

	game->map.tmp = ft_cp_dptr(game->map.map);
	i = 0;
	while (i < game->map.rows)
	{
		j = 0;
		while (j < game->map.cols)
		{
			if (game->map.tmp[i][j] == 'P')
				find_path(game, i, j);
			j++;
		}
		i++;
	}
	print_map(game);
	err_path(game);
}
