/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mom_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:15:33 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/01/05 11:13:57 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */
#include <stdio.h>
#include <unistd.h> // Para usar la función sleep()
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> // Para usar la función sleep()

#define ROWS 4
#define COLS 7

int main(void)
{
	char arr[ROWS][COLS] = {"1111111",
							"10C0X11",
							"1P01EC1",
							"1111111"}; // Inicializa el array

	// Inicializa la posición del cursor y la dirección
	int x = 1;
	int y = 3;
	int dx = 0;
	int dy = 1;
	while (1)
	{
		// Coloca un 'X' en la posición actual y borra el 'X' anterior

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
		arr[x][y] = 'X';
		arr[x - dx][y - dy] = '0';
		// Mueve el cursor en la dirección actual
		x += dx;
		y += dy;

		// Si el cursor llega a un límite, cambia la dirección
		if (x == 0 || x == ROWS - 1)
		{
			dx = -dx;
		}
		if (y == 0 || y == COLS - 1)
		{
			dy = -dy;
		}

		// Espera 1 segundo antes de mover el cursor de nuevo
		sleep(1);
	}

	return 0;
}
