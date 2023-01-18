/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_path_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:33:11 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/01/18 19:31:38 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "so_long_bonus.h"

void static	find_path(t_game *game, int row, int col, int **collected)
{
	int		rows;
	int		cols;
	char	**arr;

	rows = game->map.rows;
	cols = game->map.cols;
	arr = game->map.tmp;
	if (row < 0 || row >= rows || col < 0 || col >= cols
		|| arr[row][col] == '1' || arr[row][col] == '@')
		return ;
	if (arr[row][col] == 'E')
		return ;
	if (arr[row][col] == 'C' && !collected[row][col])
		collected[row][col] = TRUE;
	arr[row][col] = '@';
	find_path(game, row - 1, col, collected);
	find_path(game, row, col + 1, collected);
	find_path(game, row + 1, col, collected);
	find_path(game, row, col - 1, collected);
}

void static	err_exit(t_game *game, int x, int y)
{
	if (game->map.tmp[x - 1][y] != '@' && game->map.tmp[x + 1][y] != '@'
		&& game->map.tmp[x][y + 1] != '@' && game->map.tmp[x][y - 1] != '@')
	{
		ft_message(WARNING, MSG_WAR_6);
		exit(EXIT_FAILURE);
	}
}

void static	err_path(t_game *game)
{
	int	i;
	int	j;

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

void free_arr_int(int **arr)
{
	int i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

void	ctrl_path(t_game *game)
{
	int	i;
	int	j;
	int	**collected;

	collected = (int **)ft_calloc(game->map.rows + 1, sizeof(int *));
	i = -1;
	while (++i < game->map.rows)
		collected[i] = (int *)ft_calloc(game->map.cols + 1, sizeof(int *));
	game->map.tmp = ft_cp_dptr(game->map.map);
	i = -1;
	while (++i < game->map.rows)
	{
		j = -1;
		while (++j < game->map.cols)
		{
			if (game->map.tmp[i][j] == 'P')
				find_path(game, i, j, collected);
		}
	}
	err_path(game);
	free_arr_int(collected);
}
