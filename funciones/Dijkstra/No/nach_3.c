/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nach_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:18:32 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/28 00:05:17 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_ROWS 4
#define MAX_COLS 7
#define NUM_NODES 6
#define UNDEFINED -1
#define TRUE 1
#define FALSE 0

// Node structure to represent a node in the graph
struct Node
{
	int row;
	int col;
	int distance;
	int predecessor;
};

// Function prototypes
void dijkstra(char arr[MAX_ROWS][MAX_COLS], struct Node nodes[NUM_NODES]);
void printPath(struct Node nodes[NUM_NODES], int target);
int minDistanceNode(struct Node nodes[NUM_NODES], int visited[]);
int isInArray(int value, int array[], int size);

int main(void)
{
	// Initialize the 2D array
	char arr[MAX_ROWS][MAX_COLS] = {
		"1111111",
		"10A0011",
		"1P00E01",
		"1111111"};

	// Initialize the nodes
	struct Node nodes[NUM_NODES] = {
		{0, 0, INT_MAX, UNDEFINED},
		{0, 0, INT_MAX, UNDEFINED},
		{0, 0, INT_MAX, UNDEFINED},
		{0, 0, INT_MAX, UNDEFINED},
		{0, 0, INT_MAX, UNDEFINED},
		{0, 0, INT_MAX, UNDEFINED}};

	// Run Dijkstra's algorithm
	dijkstra(arr, nodes);

	// Print the shortest path
	printPath(nodes, 5);

	return 0;
}

// Function to run Dijkstra's algorithm
void dijkstra(char arr[MAX_ROWS][MAX_COLS], struct Node nodes[NUM_NODES])
{
	// Initialize the source node
	int source = 2;
	nodes[source].distance = 0;

	// Initialize the visited array
	int visited[NUM_NODES] = {FALSE};

	// Find the shortest path for all nodes
	for (int i = 0; i < NUM_NODES - 1; i++)
	{
		// Find the next node with the minimum distance
		int u = minDistanceNode(nodes, visited);

		// Mark the chosen node as visited
		visited[u] = TRUE;

		// Update the distance of the neighbors of the chosen node
		for (int v = 0; v < NUM_NODES; v++)
		{
			// Check if the node is unvisited and there is an edge between u and v
			if (!visited[v] && arr[nodes[u].row][nodes[u].col] == '1' && arr[nodes[v].row][nodes[v].col] == '1')
			{
				// Calculate the distance between u and v
				int distance = abs(nodes[u].row - nodes[v].row) + abs(nodes[u].col - nodes[v].col);

				// Update the distance and predecessor of v if the current distance is greater than the new distance
				if (nodes[v].distance > nodes[u].distance + distance)
				{
					nodes[v].distance = nodes[u].distance + distance;
					nodes[v].predecessor = u;
				}
			}
		}
	}
}

// Function to find the node with the minimum distance
int minDistanceNode(struct Node nodes[NUM_NODES], int visited[])
{
	// Initialize the minimum distance to a large value
	int minDistance = INT_MAX;
	int minNode = UNDEFINED;

	// Find the node with the minimum distance
	for (int i = 0; i < NUM_NODES; i++)
	{
		if (!visited[i] && nodes[i].distance <= minDistance)
		{
			minDistance = nodes[i].distance;
			minNode = i;
		}
	}

	return minNode;
}

// Function to print the shortest path
void printPath(struct Node nodes[NUM_NODES], int target)
{
	// Print the path in reverse order
	if (nodes[target].predecessor != UNDEFINED)
	{
		printPath(nodes, nodes[target].predecessor);
	}
	printf("(%d, %d) ", nodes[target].row, nodes[target].col);
}
