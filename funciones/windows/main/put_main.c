/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:55:59 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/09 19:44:09 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <mlx.h>

int ft_free_map(void *mlx)
{

	exit(1);
	return (0);
}

int main(void)
{
	void *mlx;
	void *win;
	void *img_rabbit;

	char *path_rabbit = "./bigmom_sm.xpm";

	int img_width;
	int img_height;

	mlx = mlx_init();
	// win = mlx_new_window(mlx, 640, 480, "nach131 So Long");
	win = mlx_new_window(mlx, 20 * 32, 15 * 32, "nach131 So Long");
	img_rabbit = mlx_xpm_file_to_image(mlx, path_rabbit, &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img_rabbit, 0, 0);

	mlx_hook(win, 17, 0, ft_free_map, mlx);
	mlx_loop(mlx);
}

//  gcc -framework OpenGL -framework AppKit put_img.c ../../sources/mlx/libmlx.a
