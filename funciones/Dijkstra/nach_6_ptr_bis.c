/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nach_6_ptr_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:18:32 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/01/16 15:46:00 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */
#include <stdio.h>
#include <stdbool.h>
#include "../../sources/libft/inc/libft.h"

// #define ROWS 10
// #define COLS 26
// ya las cuento en la funcion
int ROWS = 0;
int COLS = 0;

// bool collected[ROWS][COLS];
bool **collected;

void findA(char **arr, int row, int col, int gols, int total_gols)
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
	// int ROWS = 0;
	// int COLS = 0;
	char **arr;

	// arr = ft_file_to_dptr("../../sources/maps/42Barcelona.ber", 0);
	arr = ft_file_to_dptr("../../sources/maps/fail/imposible_exit2.ber", 0);
	// arr = ft_file_to_dptr("../../sources/maps/fail/imposible_exit2.ber", 0);

	// contamos ROWS y COLS
	while (arr[ROWS])
		ROWS++;
	while (arr[0][COLS])
		COLS++;

	collected = (bool **)ft_calloc(ROWS + 1, sizeof(bool *));
	int i = 0;
	while (i < ROWS)
	{
		collected[i] = (bool *)ft_calloc(COLS + 1, sizeof(bool *));
		i++;
	}

	int gols;
	// contar cuantos Coleccionables
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
				findA(arr, i, j, gols, total_gols);
		}
	}

	// Imprimimos el resultado
	system("clear");

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
	// system("clear");

	// for (int i = 0; i < ROWS; i++)
	// {
	// 	for (int j = 0; j < COLS; j++)
	// 	{
	// 		printf("%c ", collected[i][j]);
	// 	}
	// 	printf("\n");
	// }

	return 0;
}

// 1 1 1 1 1 1 1 1 1
// 1 @ @ @ @ @ @ @ 1
// 1 @ @ 1 @ @ 1 1 1
// 1 1 @ @ @ 1 0 C 1
// 1 @ @ @ @ 1 1 1 1
// 1 @ @ @ @ @ @ @ 1
// 1 1 1 1 1 1 1 1 1

// ../../sources/libft/libft.a
