/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nach_6_bis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:18:32 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/01/16 14:51:06 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdio.h>
#include <stdbool.h>

#define ROWS 6
#define COLS 8

bool collected[ROWS][COLS];

void findA(char arr[ROWS][COLS], int row, int col, int gols, int total_gols)
{
	// Agregar esta línea de código
	if (gols != total_gols)
	{
		return;
	}
	if (row < 0 || row >= ROWS || col < 0 || col >= COLS || arr[row][col] == '1' || arr[row][col] == '@')
	{
		return;
	}
	if (arr[row][col] == 'E')
	{
		return;
	}
	// Marcamos la celda como visitada
	if (arr[row][col] == 'C' && !collected[row][col])
	{
		collected[row][col] = true;
		gols++;
	}
	arr[row][col] = '@';

	// Buscamos A en las celdas adyacentes
	findA(arr, row - 1, col, gols, total_gols); // arriba
	findA(arr, row, col + 1, gols, total_gols); // derecha
	findA(arr, row + 1, col, gols, total_gols); // abajo
	findA(arr, row, col - 1, gols, total_gols); // izquierda
}
int main()
{
	char arr[ROWS][COLS] = {
		"11111111",
		"10C000C1",
		"1111E111",
		"1P0110C1",
		"00000000",
		"11111111"};
	int gols = 0;
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
	int total_gols = gols;

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
