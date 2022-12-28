/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:33:11 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/28 15:42:00 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "so_long.h"

void findA(t_game *game, int row, int col, int *gols)
{
	int ROWS = game->map.rows;
	int COLS = game->map.cols;
	char **arr = game->map.tmp;

	if (row < 0 || row >= ROWS || col < 0 || col >= COLS || arr[row][col] == '1' || arr[row][col] == '@' || (arr[row][col] == 'E' && gols < 0))
		return;

	if (arr[row][col] == 'C')
		*gols -= 1;
	arr[row][col] = '@';
	findA(game, row - 1, col, gols);
	findA(game, row, col + 1, gols);
	findA(game, row + 1, col, gols);
	findA(game, row, col - 1, gols);
}

void err_path(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (i < game->map.rows)
	{
		j = 0;
		while (j < game->map.cols)
		{
			if (game->map.tmp[i][j] == 'P' || game->map.tmp[i][j] == 'C' || game->map.tmp[i][j] == 'E')
			{
				ft_message(WARNING, MSG_WAR_6);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

void ctrl_path(t_game *game)
{

	int gols;
	int i;
	int j;

	gols = game->map.objets.goals;
	game->map.tmp = ft_cp_dptr(game->map.map);
	i = 0;
	while (i < game->map.rows)
	{
		j = 0;
		while (j < game->map.cols)
		{
			if (game->map.tmp[i][j] == 'P')
				findA(game, i, j, &gols);
			j++;
		}
		i++;
	}
	err_path(game);
}
