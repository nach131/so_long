/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilizadas.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:55:25 by nacho             #+#    #+#             */
/*   Updated: 2023/04/02 21:07:09 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../sources/mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img;
}			t_game;

enum
{
	ON_KEYPRESS = 2,
	ON_DESTROY = 17,
	KEY_1 = 18, // new img & put img to windows
	KEY_2 = 19,
	KEY_3 = 20,
	KEY_ESC = 53,
};

void	ft_new_img(t_game *game)
{
	int	len;

	mlx_destroy_image(game->mlx, game->img);
	game->img = mlx_xpm_file_to_image(game->mlx,
			"../../../sources/xpm/rabbit/rabbit2.xpm", &len, &len);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 2 * 32, 32);
}

void	ft_move_img(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img, 2 * 32, 2 * 32);
}

void	ft_move_clean(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 2 * 32, 0);
}

void	key_push(int key, t_game *game)
{
	printf("%d\n", key);
	if (key == KEY_1)
		ft_new_img(game);
	else if (key == KEY_2)
		ft_move_img(game);
	else if (key == KEY_3)
		ft_move_clean(game);
	else if (key == KEY_ESC)
		exit(0);
}

int	main(void)
{
	t_game	game;
	int		len;

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 32 * 5, 32 * 3, "nach131 So Long");
	game.img = mlx_xpm_file_to_image(game.mlx,
			"../../../sources/xpm/logo/logo0.xpm", &len, &len);
	mlx_put_image_to_window(game.mlx, game.win, game.img, 2 * 32, 32);
	mlx_hook(game.win, ON_DESTROY, 1L << 0, (void *)exit, &game);
	// mlx_hook(game.win, ON_KEYPRESS, 1L << 0, (void *)key_push, &game);
	mlx_key_hook(game.win, (void *)key_push, &game);
	mlx_loop(game.mlx);
	return (0);
}

//  gcc -framework OpenGL
	-framework AppKit utilizadas.c ../../../sources/mlx/libmlx.a

// void	*mlx_init(void);
// void	*mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);
// void	*mlx_xpm_file_to_image(void *xvar,char *file,int *width,int *height)
// int		mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr,
				int x, int y);

// int		mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(),
				void *param);
// int		mlx_key_hook(void *win_ptr, int (*funct_ptr)(), void *param);

// int		mlx_loop_hook(void *mlx_ptr, int (*funct_ptr)(), void *param);
// int		mlx_loop(void *mlx_ptr);
