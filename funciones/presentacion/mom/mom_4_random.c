/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mom_4_random.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:15:33 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/02/13 10:22:06 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdio.h>
#include <unistd.h> // Para usar la función sleep()
#include <stdlib.h>

// ESTE ES EL QUE FUNCIONA BIEN

#define ROWS 6
#define COLS 11

enum
{
	RIGHT,
	LEFT,
	DOWN,
	UP
};

int main(void)
{
	char arr[ROWS][COLS] = {"11111111111",
							"1X0000C0101",
							"1000C011001",
							"100C0000011",
							"1P001E001C1",
							"11111111111"};

	// Inicializa la posición del cursor y la dirección
	int x = 1;
	int y = 1;
	int px = 1;
	int py = 1;
	int move;

	while (1)
	{
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
		move = rand() % 4;

		if (move == RIGHT)
			py += 1;
		else if (move == LEFT)
			py -= 1;
		else if (move == DOWN)
			px += 1;
		else if (move == UP)
			px -= 1;
		if (arr[px][py] != '1' && arr[px][py] != 'E')
		{
			arr[x][y] = '+';
			arr[px][py] = 'X';
			x = px;
			y = py;
		}
		else
		{
			px = x;
			py = y;
		}

		printf("numero: %d\n", move);
		// Espera 1 segundo antes de mover el cursor de nuevo
		usleep(1000);
	}

	return 0;
}
