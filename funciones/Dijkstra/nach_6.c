/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nach_6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:18:32 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/01/05 12:10:27 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */
#include <stdio.h>
#include <stdbool.h>

#define ROWS 4
#define COLS 7

void findA(char arr[ROWS][COLS], int row, int col, int gols)
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
	char arr[ROWS][COLS] = {"1111111",
							"10C0X11",
							"1P01EC1",
							"1111111"};

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
