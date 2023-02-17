/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mom_5_persecucion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:15:33 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/02/14 23:31:42 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdio.h>
#include <unistd.h> // Para usar la función sleep()
#include <stdlib.h>
#include <stdio.h>

#define ROWS 6
#define COLS 11

char arr[ROWS][COLS] = {
	"11111111111",
	"1X0000C0101",
	"1000C011001",
	"100C0000011",
	"1001E00P1C1",
	"11111111111"};

// Función para imprimir el estado actual del array
void print_array()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
			printf("%c ", arr[i][j]);
		printf("\n");
	}
}

int main()
{
	// Coordenadas iniciales de X y P
	int x_row = 1;
	int x_col = 1;
	int p_row = 4;
	int p_col = 7;

	// Bucle infinito
	while (1)
	{
		// Limpia la pantalla y imprime el estado actual del array
		system("clear");
		print_array();

		// Verifica si P está más cerca en la fila o en la columna
		int row_diff = p_row - x_row;
		int col_diff = p_col - x_col;
		// if (row_diff > col_diff)
		if (abs(row_diff) > abs(col_diff))
		{
			// Si P está más lejos en la columna, se mueve en la fila
			if (row_diff > 0)
				// Si P está debajo de X, X se mueve hacia abajo
				x_row++;
			else
				// Si P está arriba de X, X se mueve hacia arriba
				x_row--;
		}
		else
		{
			// Si P está más lejos en la fila, se mueve en la columna
			if (col_diff > 0)
				// Si P está a la derecha de X, X se mueve hacia la derecha
				x_col++;
			else
				// Si P está a la izquierda de X, X se mueve hacia la izquierda
				x_col--;
		}

		// Actualiza la posición de X en el array
		arr[x_row][x_col] = '-';
		arr[p_row][p_col] = 'P';

		// Pausa el programa por 1 segundo
		sleep(1);
	}

	return 0;
}
