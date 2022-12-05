/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nueva.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:55:59 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/05 11:58:51 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "../../sources/mlx/mlx.h"

int main()
{
	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, 640, 480, "nach131 So Long");
	mlx_loop(mlx);
}

// gcc - framework OpenGL - framework AppKit nueva.c../../ sources / mlx / libmlx.a
