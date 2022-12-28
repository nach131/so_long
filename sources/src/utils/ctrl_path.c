/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:33:11 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/28 15:10:21 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "so_long.h"

void findA(t_game *game, char **arr, int row, int col, int *gols)
{
	int ROWS = game->map.rows;
	int COLS = game->map.cols;
	// int gols = game->map.objets.goals;

	if (row < 0 || row >= ROWS || col < 0 || col >= COLS || arr[row][col] == '1' || arr[row][col] == '@' || (arr[row][col] == 'E' && gols < 0))
	{
		// Si el índice está fuera del rango del arreglo, si encontramos un muro o si ya hemos visitado esta celda, entonces retornamos
		return;
	}

	// Marcamos la celda como visitada
	if (arr[row][col] == 'C')
		*gols -= 1;
	arr[row][col] = '@';

	// Buscamos A en las celdas adyacentes
	findA(game, arr, row - 1, col, gols); // arriba
	findA(game, arr, row, col + 1, gols); // derecha
	findA(game, arr, row + 1, col, gols); // abajo
	findA(game, arr, row, col - 1, gols); // izquierda
}

void ctrl_path(t_game *game)
{

	int gols;

	gols = game->map.objets.goals;

	char **tmp;
	tmp = ft_cp_dptr(game->map.map);

	int i = 0;
	int j;
	while (i < game->map.rows)
	{
		j = 0;
		while (j < game->map.cols)
		{
			if (tmp[i][j] == 'P')
				findA(game, tmp, i, j, &gols);
			j++;
		}
		i++;
	}

	i = 0;
	while (tmp[i])
	{
		ft_printf(RED "%s\n" WHITE, tmp[i]);
		i++;
	}

	ft_free_dptr(tmp);
}
