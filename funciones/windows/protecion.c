/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protecion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:55:59 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/11 04:12:10 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <mlx.h>
#include <stdlib.h>

int ft_free_map(void *mlx, void *win)
{
	// free(win);
	exit(1);
	return (0);
}

int main()
{
	void *mlx;
	void *win;

	mlx = mlx_init();

	if (mlx == NULL)
		return (EXIT_FAILURE);
	win = mlx_new_window(mlx, 640, 480, "nach131 So Long");
	if (win == NULL)
	{
		free(win);
		return (EXIT_FAILURE);
	}
	mlx_hook(win, 17, 0, ft_free_map, mlx);
	mlx_loop(mlx);
}

// gcc - framework OpenGL - framework AppKit nueva.c../../ sources / mlx / libmlx.a
