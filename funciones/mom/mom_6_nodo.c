/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mom_6_nodo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:15:33 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/01/06 20:04:22 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdio.h>
#include <unistd.h> // Para usar la función sleep()
#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 6
#define COLS 11

char arr[ROWS][COLS] = {
	"11111111111",
	"1X0000C0101",
	"1000C011001",
	"100C0000011",
	"1P001E001C1",
	"11111111111"};

// Estructura para representar un nodo en el grafo
struct Node
{
	int row;
	int col;
};

// Función para imprimir el estado actual del arreglo
void print_array()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
}

// Función para verificar si una posición es válida y no es un obstáculo
bool is_valid_position(int row, int col)
{
	return row >= 0 && row < ROWS && col >= 0 && col < COLS && arr[row][col] != '1';
}

int main()
{
	// Coordenadas iniciales de X y P
	int x_row = 1;
	int x_col = 1;
	int p_row = 4;
	int p_col = 1;

	// Bucle infinito
	while (1)
	{
		// Limpia la pantalla y imprime el estado actual del arreglo
		system("cls");
		print_array();

		// Crea una cola para almacenar los nodos por explorar
		struct Node queue[ROWS * COLS];
		int head = 0;
		int tail = 0;

		// Agrega la posición inicial de X a la cola
		queue[tail].row = x_row;
		queue[tail].col = x_col;
		tail++;

		// Marca la posición inicial de X como visitada
		arr[x_row][x_col] = 'V';

		// Bucle mientras la cola no esté vacía
		while (head < tail)
		{
			// Obtiene el nodo actual de la cabeza de la cola
			struct Node node = queue[head];
			head++;

			// Si el nodo actual es la posición final de P, se ha encontrado un camino
			if (node.row == p_row
