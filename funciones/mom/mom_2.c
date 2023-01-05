/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mom_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:15:33 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/01/05 10:26:18 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */
#include <stdio.h>
#include <unistd.h> // Para usar la función sleep()
#include <stdlib.h>

#define ROWS 4
#define COLS 7

int main(void)
{
	char arr[ROWS][COLS] = {"1111111",
							"10C0X11",
							"1P01EC1",
							"1111111"}; // Inicializa el array

	int x = 1;
	int y = 3;
	while (1)
	{
		// Coloca un 'X' en la posición actual y borra el 'X' anterior
		arr[x][y] = 'X';
		arr[x][y - 1] = '0';

		// Muestra el array en pantalla
		system("clear");
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
				printf("%c", arr[i][j]);
			}
			printf("\n");
		}

		// Mueve el cursor a la derecha
		y++;
		if (y == COLS - 1)
		{ // Si llega al límite, vuelve al inicio
			y = 1;
		}

		// Espera 1 segundo antes de mover el cursor de nuevo
		sleep(1);
	}

	return 0;
}
