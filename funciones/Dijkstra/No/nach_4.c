/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nach_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:18:32 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/28 00:22:20 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */
// #include <iostream>
// #include <queue>
#include <utility> // Para usar la estructura de datos "pair"

using namespace std;

const int filas = 4;
const int columnas = 7;

// Matriz del laberinto
char laberinto[filas][columnas] = {{"1111111"},
								   {"10A0011"},
								   {"1P00E01"},
								   {"1111111"}};

// Matriz de distancias
int distancia[filas][columnas];

// Arreglo de movimientos para recorrer el laberinto
int mov_fila[4] = {-1, 0, 1, 0};
int mov_columna[4] = {0, 1, 0, -1};

// Bandera para indicar si se ha encontrado el nodo final
bool encontrado = false;

// Función para encontrar el camino desde el nodo final hasta el inicial
void imprimir_camino(pair<int, int> nodo)
{
	if (nodo.first == -1 && nodo.second == -1)
		return;																	 // Caso base
	imprimir_camino(make_pair(distancia[nodo.first][nodo.second], nodo.second)); // Recursión
	cout << "(" << nodo.first << ", " << nodo.second << ") ";
}

int main()
{
	// Inicializamos la matriz de distancias con valores muy grandes
	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			distancia[i][j] = 1e9;
		}
	}

	// Inicializamos la cola con el nodo inicial
	queue<pair<int, int>> cola;
	pair<int, int> inicio;
	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			if (laberinto[i][j] == 'P')
			{
				inicio = make_pair(i, j);
				distancia[i][j] = -1;
				cola.push(inicio);
			}
		}
	}

	// Bucle principal del algoritmo BFS
	while (!cola.empty() && !encontrado)
	{
		// Extraemos el primer elemento de la cola y lo almacenamos en la variable nodo_actual
		pair<int, int> nodo_actual = cola.front();
		cola.pop();
		// Recorremos todos los vecinos de nodo_actual
		for (int i = 0; i < 4; i++)
		{
			int fila_vecino = nodo_actual.first + mov_fila[i];
			int columna_vecino = nodo_actual.second + mov_columna[i];

			// Verificamos que el vecino no sea un muro y que no haya sido visitado
			if (laberinto[fila_vecino][columna_vecino] != '1' && distancia[fila_vecino][columna_vecino] == 1e9)
			{
				// Marcamos el vecino como visitado y lo añadimos a la cola
				distancia[fila_vecino][columna_vecino] = nodo_actual.second;
				cola.push(make_pair(fila_vecino, columna_vecino));

				// Si el vecino es el nodo final, marcamos la bandera y terminamos la búsqueda
				if (laberinto[fila_vecino][columna_vecino] == 'E')
				{
					encontrado = true;
					break;
				}
			}
		}
	}

	// Si se ha encontrado el nodo final, imprimimos el camino desde el nodo final hasta el inicial
	if (encontrado)
	{
		cout << "Camino encontrado: ";
		imprimir_camino(make_pair(filas - 1, columnas - 1));
	}
	else
	{
		cout << "No se ha encontrado un camino hasta el nodo final." << endl;
	}

	return 0;
}
