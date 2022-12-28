/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nach_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:18:32 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/28 08:35:33 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */
#include <stdio.h>
#include <stdbool.h>

// MO RECOJE TODAS LAS A

#define ROW 4
#define COL 7

// estructura para representar una celda en el laberinto
struct Cell
{
	int row;
	int col;
};

// matrices para representar los movimientos posibles desde una celda
int row[] = {-1, 0, 0, 1};
int col[] = {0, -1, 1, 0};

// función para verificar si una celda (row, col) está dentro de los límites del laberinto y si es una celda válida
bool isValidMove(char maze[ROW][COL], bool visited[ROW][COL], int row, int col)
{
	return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && (maze[row][col] == '0' || maze[row][col] == 'E') && !visited[row][col];
}

// función para encontrar el camino desde 'P' hasta 'E' en el laberinto
bool findPath(char maze[ROW][COL], bool visited[ROW][COL], struct Cell current, struct Cell dest)
{
	// marcar la celda actual como visitada
	visited[current.row][current.col] = true;

	// si la celda actual es la celda de destino, se ha encontrado un camino
	if (current.row == dest.row && current.col == dest.col)
	{
		return true;
	}

	// probar todos los movimientos posibles desde la celda actual
	for (int i = 0; i < 4; i++)
	{
		int newRow = current.row + row[i];
		int newCol = current.col + col[i];
		struct Cell newCell = {newRow, newCol};

		// si el movimiento es válido y no se ha visitado, buscar un camino a partir de la nueva celda
		if (isValidMove(maze, visited, newRow, newCol) && findPath(maze, visited, newCell, dest))
		{
			return true;
		}
	}

	// si no se ha encontrado un camino, volver atrás y marcar la celda actual como no visitada
	visited[current.row][current.col] = false;
	return false;
}

int main()
{
	char maze[ROW][COL] = {"1111111",
						   "1000011",
						   "1P01EA1",
						   "1111111"};

	// encontrar la posición de 'P' y 'E' en el laberinto
	struct Cell start, end;
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (maze[i][j] == 'P')
			{
				start.row = i;
				start.col = j;
			}
			if (maze[i][j] == 'E')
			{
				end.row = i;
				end.col = j;
			}
		}
	}

	// matriz de booleanos para llevar registro de las celdas que se han visitado
	bool visited[ROW][COL];
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			visited[i][j] = false;
		}
	}

	// buscar un camino desde 'P' hasta 'E'
	if (findPath(maze, visited, start, end))
	{
		printf("Se ha encontrado un camino desde 'P' hasta 'E'\n");
	}
	else
	{
		printf("No se ha encontrado un camino desde 'P' hasta 'E'\n");
	}

	return 0;
}
