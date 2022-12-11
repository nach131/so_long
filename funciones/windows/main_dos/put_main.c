/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:55:59 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/11 03:57:10 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <mlx.h>
#include <unistd.h>

enum
{
	ON_KEYPRESS = 2,
	ON_KEYRELEASE = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

#define KEY_ESC 53
#define KEY_1 18
#define KEY_2 19

#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define KEY_W 13

#define KEY_LEFT 123
#define KEY_RIGHT 124
#define KEY_DOWN 125
#define KEY_UP 126
// int pantalla(void *mlx);

int ft_free_map(void *mlx)
{
	exit(1);
	return (0);
}

// int ft_destroy_window(void *mlx, void *win)
// {
// 	mlx_destroy_window(mlx, win);
// 	exit(0);
// 	return (0);
// }

int key_push(int key, void *mlx, void *win)
{
	if (key == KEY_ESC)
		ft_free_map(mlx);
	if (key == KEY_A || KEY_LEFT)
		write(1, "A", 1);
	if (key == KEY_1)
	{
		mlx_destroy_window(mlx, win);
		// ft_destroy_window(mlx, wim);
	}
	if (key == KEY_2)
		write(1, "Es dos\n", 7);
}

int key_pull(int key, void *mlx, void *win)
{
	if (key == KEY_ESC)
		ft_free_map(mlx);
	if (key == KEY_A || KEY_LEFT)
		write(1, "B", 1);
	if (key == KEY_1)
	{
		mlx_destroy_window(mlx, win);
		// ft_destroy_window(mlx, wim);
	}
	if (key == KEY_2)
		write(1, "Es tres\n", 8);
}
// int pantalla(void *mlx)
// {
// 	exit(1);
// 	return (0);
// 	// write(1, "@@@@@\n", 6);
// 	// void *win;
// 	// win = mlx_new_window(mlx, 10 * 32, 6 * 32, "nach131 So Long");
// }

void presentacion(void *mlx)
{
	void *win;
	void *img_rabbit;
	char *path_rabbit = "./bigmom_sm.xpm";
	int img_width;
	int img_height;
	win = mlx_new_window(mlx, 20 * 32, 15 * 32, "nach131 So Long");
	img_rabbit = mlx_xpm_file_to_image(mlx, path_rabbit, &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img_rabbit, 0, 0);
	mlx_hook(win, ON_KEYPRESS, 1L << 0, key_push, mlx);
	mlx_hook(win, ON_KEYRELEASE, 1L << 1, key_pull, mlx);

	// mlx_hook(game->mlx_window, 2, 0, key_down, game);
	// 	mlx_hook(game->mlx_window, 3, 0, key_up, game);
	mlx_hook(win, ON_DESTROY, 1L << 0, ft_free_map, mlx);
}

int main(void)
{
	void *mlx;

	mlx = mlx_init();
	// win = mlx_new_window(mlx, 640, 480, "nach131 So Long");
	presentacion(mlx);

	mlx_loop(mlx);
}

// gcc -framework OpenGL -framework AppKit put_main.c ../../../sources/mlx/libmlx.a
