/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:55:59 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/16 13:53:01 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <mlx.h>
#include "../../sources/libft/inc/libft.h"

int ft_free_map(void *mlx)
{

	exit(1);
	return (0);
}

int main(void)
{
	void *mlx;
	void *win;

	int width;
	int height;
	// char *file_name;
	void *img;
	int *data;
	int bpp;
	int size_line;
	int endian;

	char **file_name = ft_file_to_dptr("xpm/central.xpm");

	mlx = mlx_init();
	win = mlx_new_window(mlx, 20 * 32, 15 * 32, "nach131 So Long");

	void *img_rabbit_dos = mlx_xpm_file_to_image(mlx, "xpm/central_plano.xpm", &width, &height);
	// void *img_rabbit = mlx_xpm_to_image(mlx, img, &height, &height);
	// mlx_put_image_to_window(mlx, win, img_rabbit_dos, 0, 0);

	// file_name = "xpm/rabbit_front.xpm";
	img = mlx_xpm_to_image(mlx, file_name, &width, &height);
	// data = mlx_get_data_addr(img, &bpp, &size_line, &endian);
	mlx_put_image_to_window(mlx, win, img, 0, 0);

	mlx_hook(win, 17, 0, ft_free_map, mlx);
	mlx_loop(mlx);
}

//  gcc -framework OpenGL -framework AppKit put_img.c ../../sources/mlx/libmlx.a
