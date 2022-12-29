/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:55:59 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/29 00:53:35 by nmota-bu         ###   ########.fr       */
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
	void *img_shark;
	void *img_frog;
	void *img_rabbit_back;
	void *img_shark_back;
	void *img_frog_back;
	void *img_mom;
	char *path_rabbit = "xpm/rabbit_front.xpm";
	char *path_shark = "xpm/shark_front.xpm";
	char *path_frog = "xpm/frog_front.xpm";
	char *path_rabbit_b = "xpm/rabbit_back.xpm";
	char *path_shark_b = "xpm/shark_back.xpm";
	char *path_frog_b = "xpm/frog_back.xpm";
	char *path_mom = "../../sources/xpm/mom/mom0.xpm";
	int img_width;
	int img_height;

	mlx = mlx_init();
	// win = mlx_new_window(mlx, 640, 480, "nach131 So Long");
	win = mlx_new_window(mlx, 20 * 32, 15 * 32, "nach131 So Long");
	img_rabbit = mlx_xpm_file_to_image(mlx, path_rabbit, &img_width, &img_height);
	img_rabbit_back = mlx_xpm_file_to_image(mlx, path_rabbit_b, &img_width, &img_height);
	img_shark = mlx_xpm_file_to_image(mlx, path_shark, &img_width, &img_height);
	img_shark_back = mlx_xpm_file_to_image(mlx, path_shark_b, &img_width, &img_height);
	img_frog = mlx_xpm_file_to_image(mlx, path_frog, &img_width, &img_height);
	img_frog_back = mlx_xpm_file_to_image(mlx, path_frog_b, &img_width, &img_height);
	img_mom = mlx_xpm_file_to_image(mlx, path_mom, &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img_rabbit, 0, 0);
	mlx_put_image_to_window(mlx, win, img_rabbit_back, 0, 32);
	mlx_put_image_to_window(mlx, win, img_shark, 32, 0);
	mlx_put_image_to_window(mlx, win, img_shark_back, 32, 32);
	mlx_put_image_to_window(mlx, win, img_frog, 64, 0);
	mlx_put_image_to_window(mlx, win, img_frog_back, 64, 32);
	mlx_put_image_to_window(mlx, win, img_mom, 0, 0);
	mlx_hook(win, 17, 0, ft_free_map, mlx);
	mlx_loop(mlx);
}

//  gcc -framework OpenGL -framework AppKit put_img.c ../../sources/mlx/libmlx.a
