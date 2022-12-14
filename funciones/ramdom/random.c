/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:46:37 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/13 19:39:01 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

int main(void)
{

	srand(time(NULL));
	int number = rand() % 5;

	// char arr[6][24] = {"xpm/mis/rocks.xpm",
	// 				   "xpm/mis/rock.xpm",
	// 				   "xpm/mis/tree_green.xpm",
	// 				   "xpm/mis/tree_moles.xpm",
	// 				   "xpm/mis/tree_orange.xpm",
	// 				   "xpm/mis/tree_ping.xpm"};

	// printf("Examen: %d\n", rand() % 6 + 1);
	printf("%s\n", arr[number]);
	printf("random: %d\n", number);
}
