/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doble_ptr_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 23:54:32 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/14 23:54:38 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

void hija(int **doble_puntero) {
  // Declara una variable local que apunte al valor del doble puntero
  int *puntero = *doble_puntero;

  // Asigna un nuevo valor a la variable local
  *puntero = 5;

  // Actualiza el valor del doble puntero en la función padre
  **doble_puntero = *puntero;
}

void padre() {
  // Declara un entero y un puntero a entero
  int valor = 0;
  int *puntero = &valor;

  // Imprime el valor original
  printf("Valor original: %d\n", valor);

  // Llama a la función hija y le pasa el doble puntero
  hija(&puntero);

  // Imprime el valor actualizado
  printf("Valor actualizado: %d\n", valor);
}
