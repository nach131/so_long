/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nach_7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:18:32 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/01/15 23:35:48 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Este código utiliza una estructura Node para almacenar las coordenadas de
// cada nodo, una matriz visited para marcar los nodos que ya se han visitado,
// y las variables sx, sy, ex, ey para guardar las coordenadas iniciales y finales.
// La función BFS utiliza una cola para almacenar los nodos a visitar y
//  realiza un ciclo while hasta que se ha llegado al nodo final o no hay más nodos
//   por visitar. En cada iteración, se verifica si se encuentra un 'C' en el nodo
//   actual y si es así, se imprime su posición. Luego, se verifican
//   los nodos adyacentes y se marcan como visitados si no lo han sido antes y
//    no son un muro.

#define ROWS 4
#define COLS 7

struct Node
{
	int x, y;
};

void BFS(char arr[ROWS][COLS], bool visited[ROWS][COLS], int sx, int sy, int ex, int ey)
{
	struct Node queue[ROWS * COLS];
	int head = 0, tail = 0;
	queue[tail++] = (struct Node){sx, sy};
	visited[sx][sy] = true;

	while (head != tail)
	{
		struct Node curr = queue[head++];
		if (arr[curr.x][curr.y] == 'C')
		{
			printf("Found C at (%d, %d)\n", curr.x, curr.y);
		}

		if (curr.x > 0 && !visited[curr.x - 1][curr.y] && arr[curr.x - 1][curr.y] != '1')
		{
			queue[tail++] = (struct Node){curr.x - 1, curr.y};
			visited[curr.x - 1][curr.y] = true;
		}
		if (curr.x < ROWS - 1 && !visited[curr.x + 1][curr.y] && arr[curr.x + 1][curr.y] != '1')
		{
			queue[tail++] = (struct Node){curr.x + 1, curr.y};
			visited[curr.x + 1][curr.y] = true;
		}
		if (curr.y > 0 && !visited[curr.x][curr.y - 1] && arr[curr.x][curr.y - 1] != '1')
		{
			queue[tail++] = (struct Node){curr.x, curr.y - 1};
			visited[curr.x][curr.y - 1] = true;
		}
		if (curr.y < COLS - 1 && !visited[curr.x][curr.y + 1] && arr[curr.x][curr.y + 1] != '1')
		{
			queue[tail++] = (struct Node){curr.x, curr.y + 1};
			visited[curr.x][curr.y + 1] = true;
		}
		if (curr.x == ex && curr.y == ey)
		{
			break;
		}
	}
}

int main()
{
	char arr[ROWS][COLS] = {
		"1111111",
		"10C0C11",
		"1P01EC1",
		"1111111"};

	bool visited[ROWS][COLS];
	int sx, sy, ex, ey;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			visited[i][j] = false;
			if (arr[i][j] == 'P')
			{
				sx = i;
				sy = j;
			}
			else if (arr[i][j] == 'E')
			{
				ex = i;
				ey = j;
			}
		}
	}
	BFS(arr, visited, sx, sy, ex, ey);

	return 0;
}
