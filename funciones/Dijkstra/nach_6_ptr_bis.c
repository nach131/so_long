/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nach_6_ptr_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:18:32 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/01/16 19:47:36 by nmota-bu         ###   ########.fr       */
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

void findA(char **arr, int x, int y)
{

	if (x < 0 || x >= ROWS || y < 0 || y >= COLS || arr[x][y] == '1' || arr[x][y] == '@')
		return;
	if (arr[x][y] == 'E')
		return;
	// Marcamos la celda como visitada
	if (arr[x][y] == 'C' && !collected[x][y])
		collected[x][y] = true;
	arr[x][y] = '@';

	// Buscamos A en las celdas adyacentes
	findA(arr, x - 1, y); // arriba
	findA(arr, x, y + 1); // derecha
	findA(arr, x + 1, y); // abajo
	findA(arr, x, y - 1); // izquierda
}

int main()
{

	char **arr;

	// arr = ft_file_to_dptr("../../sources/maps/42Barcelona.ber", 0);
	// arr = ft_file_to_dptr("../../sources/maps/fail/imposible_exit.ber", 0);
	arr = ft_file_to_dptr("../../sources/maps/fail/imposible_exit2.ber", 0);

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
				findA(arr, i, j);
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
	// 		printf("%d ", collected[i][j]);
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
