/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilizadas.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:55:25 by nacho             #+#    #+#             */
/*   Updated: 2023/02/13 14:52:42 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../sources/mlx/mlx.h"
#include <stdlib.h>

typedef struct s_game
{
	void *mlx;
	void *win;
	void *logo;
} t_game;

enum
{
	ON_DESTROY = 17
};

int main(void)
{
	t_game game;

	int len;

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 32 * 5, 32 * 3, "nach131 So Long");
	game.logo = mlx_xpm_file_to_image(game.mlx, "../../../sources/xpm/logo/logo0.xpm", &len, &len);
	mlx_put_image_to_window(game.mlx, game.win, game.logo, 2 * 32, 32);
	mlx_hook(game.win, ON_DESTROY, 1L << 0, (void *)exit, &game);
	mlx_loop(game.mlx);
	return (0);
}

//  gcc -framework OpenGL -framework AppKit utilizadas.c ../../../sources/mlx/libmlx.a

// void	*mlx_init();
// void	*mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);
// void	*mlx_xpm_file_to_image(void *xvar,char *file,int *width,int *height)
// void	*mlx_new_image(void *mlx_ptr, int width, int height);
// int		mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);

// int		mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(), void *param);
// int		mlx_key_hook(void *win_ptr, int (*funct_ptr)(), void *param);

// int		mlx_loop_hook(void *mlx_ptr, int (*funct_ptr)(), void *param);
// int		mlx_loop(void *mlx_ptr);
