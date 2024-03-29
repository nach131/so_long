/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nach_6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:18:32 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/01/16 14:34:01 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */
#include <stdio.h>
#include <stdbool.h>

#define ROWS 6
#define COLS 8

void findA(char arr[ROWS][COLS], int row, int col, int gols, int total_gols)
{
	if (row < 0 || row >= ROWS || col < 0 || col >= COLS || arr[row][col] == '1' || arr[row][col] == '@')
	// if (row < 0 || row >= ROWS || col < 0 || col >= COLS || arr[row][col] == '1' || arr[row][col] == '@' || (arr[row][col] == 'E' && gols == 0))
	{
		// Si el índice está fuera del rango del arreglo, si encontramos un muro o si ya hemos visitado esta celda, entonces retornamos
		return;
	}

	if (arr[row][col] == 'E' && gols != total_gols)
	{
		// Si encontramos la salida y no todas las 'C' han sido recogidas, retornamos
		return;
	}
	// Marcamos la celda como visitada
	if (arr[row][col] == 'C')
		gols--;
	arr[row][col] = '@';

	// Buscamos A en las celdas adyacentes
	findA(arr, row - 1, col, gols, total_gols); // arriba
	findA(arr, row, col + 1, gols, total_gols); // derecha
	findA(arr, row + 1, col, gols, total_gols); // abajo
	findA(arr, row, col - 1, gols, total_gols); // izquierda
}

int main()
{
	char arr[ROWS][COLS] = {"11111111",
							"10C010C1",
							"1101E101",
							"1P0100C1",
							"00000000",
							"11111111"};

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
	int total_gols = 0;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (arr[i][j] == 'C')
			{
				total_gols++;
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
				findA(arr, i, j, gols, total_gols);
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
