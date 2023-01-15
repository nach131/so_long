/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nach_6_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:18:32 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/01/16 00:08:39 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */
#include <stdio.h>
#include <stdbool.h>
#include "../../sources/libft/inc/libft.h"

// #define ROWS 10
// #define COLS 5
// ya las cuento en la funcion
int ROWS = 0;
int COLS = 0;

void findA(char **arr, int row, int col, int *gols)
{
	// if (row < 0 || row >= ROWS || col < 0 || col >= COLS || arr[row][col] == '1' || arr[row][col] == '@' || (arr[row][col] == 'E' && gols < 0))
	if (row < 0 || row >= ROWS || col < 0 || col >= COLS || arr[row][col] == '1' || arr[row][col] == '@' || (arr[row][col] == 'E' && gols))
	{
		// Si el índice está fuera del rango del arreglo, si encontramos un muro o si ya hemos visitado esta celda, entonces retornamos
		return;
	}

	// Marcamos la celda como visitada
	if (arr[row][col] == 'C')
		*gols -= 1;
	arr[row][col] = '@';

	// Buscamos A en las celdas adyacentes
	findA(arr, row - 1, col, gols); // arriba
	findA(arr, row, col + 1, gols); // derecha
	findA(arr, row + 1, col, gols); // abajo
	findA(arr, row, col - 1, gols); // izquierda
}

int main()
{
	// int ROWS = 0;
	// int COLS = 0;
	char **arr;

	// arr = ft_file_to_dptr("../../sources/maps/min.ber", 0);
	// arr = ft_file_to_dptr("../../sources/maps/fail/imposible.ber", 0);
	arr = ft_file_to_dptr("../../sources/maps/fail/imposible-wall.ber", 0);

	while (arr[ROWS])
		ROWS++;
	while (arr[0][COLS])
		COLS++;

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

	// Buscamos A desde P hasta E
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (arr[i][j] == 'P')
			{
				findA(arr, i, j, &gols);
			}
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
