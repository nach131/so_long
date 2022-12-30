/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 19:37:57 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/30 20:46:45 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

// TELETRANSPORTACION DE ENEMIGO
// mom tiene un 2x3 de ocupacion, hay que guardar todos eso valores sustituirlos por
// X, realizar el teletransporte y volver a colocar los valores antetiores,
// recargar el mapa en la posicion y cargar enemy en la nueva posicion
// el desplazamiento no puede ser en los muros ni menos de 2 por debajo
//  ni menos de dos por la derecha.
//

// rows:11, cols:22

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int random_num(int n)
{
	// Inicializa la semilla del generador de números aleatorios
	// con la hora actual del sistema
	// srand(time(0));

	// Genera un número aleatorio entre 1 y 10
	return (rand() % n + 1);
}

int main()
{
	int i = 0;

	while (i < 10)
	{
		printf("Numero aleatorio: %d\n", random_num(10));
		i++;
	}

	return 0;
}

#include <stdlib.h>
#include <time.h>

int main()
{
	// Inicializa la semilla del generador de números aleatorios
	// con la hora actual del sistema
	srand(time(0));

	// Genera un número aleatorio entre 0 y 25
	int aleatorio = rand() % 26;

	// Convierte el número aleatorio a una letra del abecedario
	char letra = 'a' + aleatorio;

	printf("Letra aleatoria: %c\n", letra);

	return 0;
}
