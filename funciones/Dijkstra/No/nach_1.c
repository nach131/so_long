/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nach_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:18:32 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/27 23:07:21 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INFINITY 99999999
#define MAX_ROWS 6
#define MAX_COLS 21

typedef struct
{
	int x;
	int y;
} Coordinate;

typedef struct
{
	Coordinate position;
	int distance;
	bool visited;
} Node;

int minDistance(Node nodes[MAX_ROWS][MAX_COLS], int n, int m)
{
	// Inicializar el nodo con la distancia mínima
	int min = INFINITY;
	int minIndex;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!nodes[i][j].visited && nodes[i][j].distance <= min)
			{
				min = nodes[i][j].distance;
				minIndex = i * MAX_COLS + j;
			}
		}
	}

	return minIndex;
}

void dijkstra(char map[MAX_ROWS][MAX_COLS], Coordinate start, Coordinate end)
{
	// Inicializar los nodos con sus posiciones y distancias infinitas
	Node nodes[MAX_ROWS][MAX_COLS];
	for (int i = 0; i < MAX_ROWS; i++)
	{
		for (int j = 0; j < MAX_COLS; j++)
		{
			nodes[i][j].position.x = i;
			nodes[i][j].position.y = j;
			nodes[i][j].distance = INFINITY;
			nodes[i][j].visited = false;
		}
	}

	// Establecer la distancia del nodo de inicio en 0
	nodes[start.x][start.y].distance = 0;

	// Repetir el siguiente proceso hasta que se hayan visitado todos los nodos
	for (int i = 0; i < MAX_ROWS * MAX_COLS - 1; i++)
	{
		// Encontrar el nodo con la distancia mínima
		int u = minDistance(nodes, MAX_ROWS, MAX_COLS);

		// Marcar el nodo como visitado
		nodes[u / MAX_COLS][u % MAX_COLS].visited = true;

		// Recorrer todos los vecinos del nodo
		for (int v = 0; v < MAX_ROWS * MAX_COLS; v++)
		{
			// Obtener las coordenadas del vecino
			int x = v / MAX_COLS;
			int y = v % MAX_COLS;

			// Verificar si el vecino es un camino y si no ha sido visitado
	  if (map[x][y] == '1
