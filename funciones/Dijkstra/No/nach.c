/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nach.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:18:32 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/27 21:56:06 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define INF INT_MAX	 // Valor infinito para arcos con peso infinito
#define MAX_NODES 25 // Máximo número de nodos

// Estructura para representar un nodo del grafo
typedef struct node
{
	int row;		 // Fila del array donde se encuentra el nodo
	int col;		 // Columna del array donde se encuentra el nodo
	int dist;		 // Distancia desde el nodo 'P' hasta el nodo actual
	bool visited;	 // Indica si el nodo ha sido visitado o no
	int predecessor; // Índice del nodo predecesor (en el array de nodos)
} Node;

// Función para comparar dos nodos según su distancia
int compare(const void *a, const void *b)
{
	Node *n1 = (Node *)a;
	Node *n2 = (Node *)b;
	return n1->dist - n2->dist;
}

int main(void)
{
	// Array de caracteres con el mapa
	char arr[6][21] = {
		"11111111111111111111",
		"100000001000000000A1",
		"10010000011100000001",
		"11000000000000A00001",
		"1P0000110E0000000001",
		"11111111111111111111"};

	// Array de nodos para almacenar el grafo
	Node nodes[MAX_NODES];
	int num_nodes = 0; // Contador para el número de nodos del grafo

	// Recorremos el array de caracteres y creamos los nodos del grafo
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 21; j++)
		{

			// Si el carácter es un espacio en blanco, creamos un nodo para representarlo
			if (arr[i][j] == '0')
			{
				// Creamos un nuevo nodo y lo añadimos al array de nodos
				Node new_node;
				new_node.row = i;
				new_node.col = j;
				new_node.dist = INF;	   // Inicialmente, todos los nodos tienen distancia infinita
				new_node.visited = false;  // Inicialmente, ningún nodo ha sido visitado
				new_node.predecessor = -1; // Inicialmente, ningún nodo tiene predecesor
				nodes[num_nodes] = new_node;
				num_nodes++;
			}
		}
	}

	// Buscamos el nodo 'P' y lo marcamos como el nodo inicial
	int start_node = -1; // Índice del nodo inicial (en el array de nodos)
	for (int i = 0; i < num_nodes; i++)
	{
		if (arr[nodes[i].row][nodes[i].col] == 'P')
		{
			nodes[i].dist = 0; // La distancia del nodo inicial es 0
			start_node = i;
			break;
		}
	}

	// Si no encontramos el nodo inicial, terminamos el programa
	if (start_node == -1)
	{
		printf("No se encontró el nodo inicial 'P'\n");
		return 0;
	}

	// Creamos una cola para implementar el algoritmo de Dijkstra
	Node queue[MAX_NODES];
	int num_in_queue = 0; // Número de elementos en la cola

	// Añadimos el nodo inicial a la cola
	queue[num_in_queue] = nodes[start_node];
	num_in_queue++;

	// Mientras haya nodos en la cola, seguimos buscando caminos más cortos
	while (num_in_queue > 0)
	{
		// Ordenamos los nodos de la cola según su distancia (menor a mayor)
		qsort(queue, num_in_queue, sizeof(Node), compare);
		// Tomamos el nodo con menor distancia de la cola
		Node curr_node = queue[0];
		int curr_index = 0; // Índice del nodo en el array de nodos

		// Buscamos el índice del nodo en el array de nodos
		for (int i = 0; i < num_nodes; i++)
		{
			if (nodes[i].row == curr_node.row && nodes[i].col == curr_node.col)
			{
				curr_index = i;
				break;
			}
		}

		// Marcamos el nodo como visitado
		nodes[curr_index].visited;
	}
}
