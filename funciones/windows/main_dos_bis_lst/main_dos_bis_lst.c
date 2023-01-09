/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_dos_bis_lst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:55:59 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/01/09 14:06:30 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "../../../sources/mlx/mlx.h"
#include "../../../sources/libft/inc/libft.h"
#include "../../../sources/libft/inc/colors.h"
#include "../../../sources/libft/inc/ft_printf.h"

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
#define KEY_3 20

#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define KEY_W 13

typedef struct s_images
{
	void *mom;
	t_list *end;
	t_list *won;
	t_list *tmp;

} t_images;

typedef struct s_grafic
{
	void *mlx;
	void *win;
	void *img;
} t_grafic;

typedef struct s_game
{
	t_grafic grafic;
	t_images images;
	int flag;
	int type;
} t_game;

void segunda(t_game *game);
void presentacion(t_game *game);
void tercera(t_game *game);
void free_all(t_game *game);

int key_push(int key, t_game *game)
{
	if (key == KEY_ESC)
		free_all(game);
	if (key == KEY_A)
		write(1, "A", 1);
	if (key == KEY_1)
		presentacion(game);
	if (key == KEY_2)
		segunda(game);
	if (key == KEY_3)
		tercera(game);
	return (0);
}

// int key_pull(int key, t_game *game)
// {
// 	if (key == KEY_ESC)
// 		exit(0);
// 	if (key == KEY_A)
// 		write(1, "A", 1);
// 	if (key == KEY_1)
// 	{
// 		write(1, "levantado uno\n", 14);
// 	}
// 	if (key == KEY_2)
// 		write(1, "levantado dos\n", 14);
// }

void free_all(t_game *game)
{
	// mlx_destroy_image(game->grafic.mlx, game->images.lwon);
	// if (game->images.end)
	// {
	// 	ft_lstclear(&game->images.tmp, ft_lstdelone);
	// }

	if (game->images.won)
	{
		ft_printf(ORANGE "\tif\n");
		ft_lstclear(&game->images.won, ft_lstdelitem);
		// while (game->images.won)
		// {
		// 	// mlx_destroy_image(game->grafic.mlx, game->images.won);
		// 	ft_printf(RED "\t\twhile");
		// 	game->images.won = game->images.won->next;
		// }
	}

	// if (game->images.tmp)
	// {
	// 	ft_printf(CYAN "\ttmp lst\n");
	// 	ft_lstclear(&game->images.tmp, ft_lstdelitem);
	// }

	exit(0);
}

char static *path_img(char *name_img, int n)
{
	char *nbr;
	char *s1;
	char *s2;

	nbr = ft_itoa(n);
	s1 = ft_strjoin("../../../sources/xpm/", name_img);
	s2 = ft_strjoin(s1, "/");
	free(s1);
	s1 = ft_strjoin(s2, name_img);
	free(s2);
	s2 = ft_strjoin(s1, nbr);
	free(s1);
	s1 = ft_strjoin(s2, ".xpm");
	free(s2);
	free(nbr);
	return (s1);
}

void static load_image(t_game *game, char *name, int num, int type)
{
	int i;
	int w;
	int h;
	void *mlx = game->grafic.mlx;
	char *path;

	i = -1;

	while (++i < num)
	{
		path = path_img(name, i);
		if (type == 1)
			ft_lstadd_back(&game->images.end, ft_lstnew(mlx_xpm_file_to_image(game->grafic.mlx, path, &w, &h)));
		else if (type == 2)
			ft_lstadd_back(&game->images.won, ft_lstnew(mlx_xpm_file_to_image(game->grafic.mlx, path, &w, &h)));
	}
}

void tokemo(t_game *game, t_list *lst)
{
	while (lst)
		mlx_put_image_to_window(game->grafic.mlx, game->grafic.win, lst->content, 0, 0);
	lst = lst->next;
}

void loops(t_game *game)
{
	int static frame = 0;

	if (!(frame % 600))
	{
		if (game->type == 1)
		{
			mlx_put_image_to_window(game->grafic.mlx, game->grafic.win, game->images.tmp->content, 0, 0);
			game->images.tmp = game->images.tmp->next;
			if (game->images.tmp == NULL)
				game->images.tmp = game->images.end;
		}
		else if (game->type == 2)
		{
			// mlx_put_image_to_window(game->grafic.mlx, game->grafic.win, game->images.won[i], 0, 0);
			mlx_put_image_to_window(game->grafic.mlx, game->grafic.win, game->images.tmp->content, 0, 0);
			game->images.tmp = game->images.tmp->next;
			if (game->images.tmp == NULL)
				game->images.tmp = game->images.won;
		}
		frame = 1;
	}
	else
		frame++;
}

void segunda(t_game *game)
{
	game->type = 1;
	mlx_destroy_window(game->grafic.mlx, game->grafic.win);
	load_image(game, "gameover", 104, 1);

	game->grafic.win = mlx_new_window(game->grafic.mlx, 1280, 720, "Game Over");

	game->images.tmp = game->images.end;

	mlx_loop_hook(game->grafic.mlx, (void *)loops, game);
	mlx_hook(game->grafic.win, ON_KEYPRESS, 1L << 0, key_push, game);
}
//
void tercera(t_game *game)
{
	game->type = 2;
	mlx_destroy_window(game->grafic.mlx, game->grafic.win);
	load_image(game, "won", 114, 2);

	game->grafic.win = mlx_new_window(game->grafic.mlx, 1280, 720, "You Won");

	game->images.tmp = game->images.won;

	mlx_loop_hook(game->grafic.mlx, (void *)loops, game);
	mlx_hook(game->grafic.win, ON_KEYPRESS, 1L << 0, key_push, game);
}

void presentacion(t_game *game)
{

	if (game->grafic.win)
	{
		mlx_destroy_window(game->grafic.mlx, game->grafic.win);
		mlx_clear_window(game->grafic.mlx, game->grafic.win);
	}
	char *path_rabbit = "../xpm/bigmom_sm.xpm";
	int img_width;
	int img_height;

	game->grafic.win = mlx_new_window(game->grafic.mlx, 20 * 32, 15 * 32, "nach131 So Long");
	game->images.mom = mlx_xpm_file_to_image(game->grafic.mlx, path_rabbit, &img_width, &img_height);
	mlx_put_image_to_window(game->grafic.mlx, game->grafic.win, game->images.mom, 0, 0);
	mlx_hook(game->grafic.win, ON_DESTROY, 1L << 0, (void *)exit, game);
	mlx_hook(game->grafic.win, ON_KEYPRESS, 1L << 0, key_push, game);
	// mlx_hook(game->grafic.win, ON_KEYRELEASE, 1L << 0, key_pull, game);
}

int main(void)
{
	t_game game;

	ft_bzero(&game, sizeof(t_game));
	game.grafic.mlx = mlx_init();

	presentacion(&game);
	mlx_loop(game.grafic.mlx);
}

// gcc -framework OpenGL -framework AppKit main_dos_bis_lst.c ../../../sources/mlx/libmlx.a
