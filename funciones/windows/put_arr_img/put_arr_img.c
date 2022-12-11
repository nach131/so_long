/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_arr_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 12:13:23 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/11 14:10:04 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <mlx.h>
#include <unistd.h>
#include <stdio.h>

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

#define ROWS 6

#define ROCKS "../xpm/rocks.xpm"
#define FROG_F "../xpm/frog_front.xpm"
#define GRASS "../xpm/central.xpm"
#define TGREEN "../xpm/tree_GREEN.xpm"
#define DOORC "../xpm/door_closed.xpm"
#define COL "../xpm/3d_1.xpm"

int ft_free_map(void *mlx)
{
	exit(1);
	return (0);
}

void put_img(void *mlx, void *win, int x, int y, char *path)
{

	void *image;
	int img_width;
	int img_height;

	image = mlx_xpm_file_to_image(mlx, path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, image, y, x);
}

void filter(void *mlx, void *win, int x, int y, char ch)
{
	void *img_frog;
	int img_width;
	int img_height;

	if (x != 0 || y != 0)
	{
		x *= 32;
		y *= 32;
	}

	if (ch == '1')
	{
		put_img(mlx, win, x, y, TGREEN);
		printf("x:%d, y:%d\n", x, y);
	}
	if (ch == '0')
		put_img(mlx, win, x, y, GRASS);
	if (ch == 'P')
		put_img(mlx, win, x, y, FROG_F);
	if (ch == 'E')
		put_img(mlx, win, x, y, DOORC);
	if (ch == 'C')
		put_img(mlx, win, x, y, COL);
}

void windows(void *mlx)
{
	char arr[ROWS][21] = {"11111111111111111111",
						  "100000001000000000C1",
						  "10010000011100000001",
						  "11000000000000000001",
						  "1P0000110E0000000001",
						  "11111111111111111111"};
	int i = 0;
	int j;

	void *win;
	win = mlx_new_window(mlx, 20 * 32, ROWS * 32, "nach131 So Long");
	while (i < ROWS)
	{
		j = 0;
		while (arr[i][j])
		{
			filter(mlx, win, i, j, arr[i][j]);
			j++;
		}
		i++;
	}

	mlx_hook(win, ON_DESTROY, 1L << 0, ft_free_map, mlx);
}
int main(void)
{

	void *mlx;

	mlx = mlx_init();
	windows(mlx);
	mlx_loop(mlx);
}

// gcc -framework OpenGL -framework AppKit put_arr_img.c ../../../sources/mlx/libmlx.a
