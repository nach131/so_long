/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nach_7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:18:32 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/28 09:27:21 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdio.h>
#include <stdbool.h>

#define ROWS 4
#define COLS 7

// Función que realiza la búsqueda de la 'E' a partir de la posición (x, y).
bool search(char arr[ROWS][COLS], int x, int y)
{
	// Comprobamos si la posición (x, y) es una 'E'.
	if (arr[x][y] == 'E')
		return true;

	// Comprobamos si la posición (x, y) es una 'A'.
	if (arr[x][y] == 'C')
		// Convertimos la 'A' en un '0'.
		arr[x][y] = '0';
	else if (arr[x][y] != '0')
		// Si la posición (x, y) no es una 'A' ni un '0', no podemos seguir avanzando.
		return false;

	// Realizamos la búsqueda en las posiciones adyacentes.
	if (x > 0)
	{
		// Búsqueda hacia arriba.
		if (search(arr, x - 1, y))
			return true;
	}
	if (y > 0)
	{
		// Búsqueda hacia la izquierda.
		if (search(arr, x, y - 1))
			return true;
	}
	if (x < ROWS - 1)
	{
		// Búsqueda hacia abajo.
		if (search(arr, x + 1, y))
			return true;
	}
	if (y < COLS - 1)
	{
		// Búsqueda hacia la derecha.
		if (search(arr, x, y + 1))
			return true;
	}

	// Si no hemos encontrado la 'E' en ninguna de las posiciones adyacentes, devolvemos false.
	return false;
}

int main(void)
{
	char arr[ROWS][COLS] = {"1111111",
							"10C0001",
							"1P01EC1",
							"1111111"};

	// Buscamos la 'E' a partir de la posición inicial ('P').
	bool found = search(arr, 2, 1);

	if (found)
		printf("E encontrada\n");
	else
		printf("E no encontrada\n");

	return 0;
}
