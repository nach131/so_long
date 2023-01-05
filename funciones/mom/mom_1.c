/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mom_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:15:33 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/01/05 10:16:48 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define N 25

int main(void)
{
	char array[N][N] = {0}; // Inicializa el array con ceros

	// Inicializa el array con la forma que mencionaste
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i == 0 || i == N - 1 || j == 0 || j == N - 1)
			{
				array[i][j] = '1';
			}
			else if (i == 10 && j == 5)
			{
				array[i][j] = 'P';
			}
			else if (i == 10 && j == 20)
			{
				array[i][j] = 'C';
			}
			else if (i == 20 && j == 5)
			{
				array[i][j] = 'C';
			}
			else if (i == 20 && j == 20)
			{
				array[i][j] = 'C';
			}
			else if (i == 5 && j == 10)
			{
				array[i][j] = 'E';
			}
			else if (i == 20 && j == 10)
			{
				array[i][j] = 'C';
			}
		}
	}

	// Muestra el array en pantalla
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%c", array[i][j]);
		}
		printf("\n");
	}

	// Realiza el movimiento constante de 'X' en el array
	int x = 5;
	int y = 5;
	while (1)
	{
		array[x][y] = 'X'; // Coloca un 'X' en la posición actual

		// Mueve el cursor a la derecha
		y++;
		if (y == N - 1)
		{ // Si llega al límite, vuelve al inicio
			y = 1;
		}

		// Limpia la pantalla y vuelve a mostrar el array
		system("clear");
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				printf("%c", array[i][j]);
			}
			printf("\n");
		}

		// Espera 1 segundo antes de mover el cursor de nuevo
		sleep(1);
	}

	return 0;
}
