/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NO_doble_ptr_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 23:57:48 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/15 08:23:08 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdio.h>

void hija(char ***doble_puntero)
{
	// Declara una variable local que apunte al valor del doble puntero
	char **puntero = *doble_puntero;

	// Accede al elemento del array que deseas modificar y asigna un nuevo valor
	puntero[1] = "Hola";

	// Actualiza el valor del doble puntero en la función padre
	**doble_puntero = *puntero;
}

int main(void)
{
	// Declara un array de cadenas
	char *strings[] = {"Adiós", "Mundo"};

	// Declara un puntero a un array de cadenas
	char **puntero = strings;

	// Imprime el valor original del elemento
	printf("Valor original: %s\n", puntero[1]);

	// Llama a la función hija y le pasa el doble puntero
	hija(&puntero);

	// Imprime el valor actualizado del elemento
	printf("Valor actualizado: %s\n", puntero[1]);
}
