/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:55:59 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/05 13:32:43 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "../../sources/mlx/mlx.h"

int main(void)
{
	void *mlx;
	void *img;
	char *relative_path = "./rocks.xpm";
	int img_width;
	int img_height;

	mlx = mlx_init();
	void *win = mlx_new_window(mlx, 640, 480, "nach131 So Long");
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img, img_width, img_height);
	// mlx_put_image_to_window()
	mlx_loop(mlx);
}

//  gcc -framework OpenGL -framework AppKit put_img.c ../../sources/mlx/libmlx.a
