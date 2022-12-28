/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nach_6_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:18:32 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/28 10:23:04 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */
#include <stdio.h>
#include <stdbool.h>
#include "../../sources/libft/inc/libft.h"

#define ROWS 3
#define COLS 5

void findA(char **arr, int row, int col, int gols)
{
	if (row < 0 || row >= ROWS || col < 0 || col >= COLS || arr[row][col] == '1' || arr[row][col] == '@' || (arr[row][col] == 'E' && gols))
	{
		// Si el índice está fuera del rango del arreglo, si encontramos un muro o si ya hemos visitado esta celda, entonces retornamos
		return;
	}

	// Marcamos la celda como visitada
	if (arr[row][col] == 'C')
		gols--;
	arr[row][col] = '@';

	// Buscamos A en las celdas adyacentes
	findA(arr, row - 1, col, gols); // arriba
	findA(arr, row, col + 1, gols); // derecha
	findA(arr, row + 1, col, gols); // abajo
	findA(arr, row, col - 1, gols); // izquierda
}

int main()
{
	// char arr[ROWS][COLS] = {"1111111",
	// 						"10C0011",
	// 						"1P01EC1",
	// 						"1111111"};
	char **arr;

	arr = ft_file_to_dptr("../../sources/maps/min.ber", 0);

	int gols;

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (arr[i][j] == 'C')
			{
				gols++;
			}
		}
	}

	// Buscamos A desde P hasta E
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (arr[i][j] == 'P')
			{
				findA(arr, i, j, gols);
			}
		}
	}

	// Imprimimos el resultado
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}

// 1 1 1 1 1 1 1
// 1 @ @ @ @ 1 1
// 1 @ @ 1 E C 1
// 1 1 1 1 1 1 1

// ../../sources/libft/libft.a
