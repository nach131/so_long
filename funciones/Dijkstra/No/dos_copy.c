/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dos_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 18:52:52 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/27 20:54:31 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

// https://www.programiz.com/dsa/dijkstra-algorithm
// Dijkstra's Algorithm in C

#include <stdio.h>
#define INFINITY 9999
#define MAX 10

void Dijkstra(int Graph[MAX][MAX], int n, int start);

void Dijkstra(int Graph[MAX][MAX], int n, int start)
{
	int cost[MAX][MAX], distance[MAX], pred[MAX];
	int visited[MAX], count, mindistance, nextnode, i, j;

	// Creating cost matrix
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (Graph[i][j] == 0)
				cost[i][j] = INFINITY;
			else
				cost[i][j] = Graph[i][j];

	for (i = 0; i < n; i++)
	{
		distance[i] = cost[start][i];
		pred[i] = start;
		visited[i] = 0;
	}

	distance[start] = 0;
	visited[start] = 1;
	count = 1;

	while (count < n - 1)
	{
		mindistance = INFINITY;

		for (i = 0; i < n; i++)
			if (distance[i] < mindistance && !visited[i])
			{
				mindistance = distance[i];
				nextnode = i;
			}

		visited[nextnode] = 1;
		for (i = 0; i < n; i++)
			if (!visited[i])
				if (mindistance + cost[nextnode][i] < distance[i])
				{
					distance[i] = mindistance + cost[nextnode][i];
					pred[i] = nextnode;
				}
		count++;
	}

	// Printing the distance
	for (i = 0; i < n; i++)
		if (i != start)
		{
			printf("\nDistance from source to %d: %d", i, distance[i]);
		}
}
int main()
{
	int i, j, n, u;
	// int Graph[MAX][MAX], i, j, n, u;
	n = 7;

	// int Graph[MAX][MAX] = {
	// 	{1, 1, 1, 1, 1, 1, 1},
	// 	{1, 2, 0, 0, 0, 0, 1},
	// 	{1, 0, 0, 0, 0, 0, 1},
	// 	{1, 0, 0, 0, 0, 0, 1},
	// 	{1, 0, 0, 0, 0, 0, 1},
	// 	{1, 0, 0, 0, 0, 0, 1},
	// 	{1, 1, 1, 1, 1, 1, 1}};
	int Graph[MAX][MAX] = {
		{0, 0, 1, 2, 0, 0, 0},
		{0, 0, 2, 0, 0, 3, 0},
		{1, 2, 0, 1, 3, 0, 0},
		{2, 0, 1, 0, 0, 0, 1},
		{0, 0, 3, 0, 0, 2, 0},
		{0, 3, 0, 0, 2, 0, 1},
		{0, 0, 0, 1, 0, 1, 0}};

	u = 0;
	Dijkstra(Graph, n, u);

	return 0;
}

// Distance from source to 1: 3
// Distance from source to 2: 1
// Distance from source to 3: 2
// Distance from source to 4: 4
// Distance from source to 5: 4
// Distance from source to 6: 3
