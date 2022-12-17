/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:30:14 by nmota-bu          #+#    #+#             */
/*   Updated: 2022/12/17 15:49:08 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "so_long.h"
#include "images.h"
#include "../../mlx/mlx.h"

char static *path_img(char *name_img, int n)
{
	char *nbr;
	char *s1;
	char *s2;

	nbr = ft_itoa(n);
	s1 = ft_strjoin("xpm/", name_img);
	s2 = ft_strjoin(s1, "/");
	free(s1);
	s1 = ft_strjoin(s2, name_img);
	free(s2);
	s2 = ft_strjoin(s1, nbr);
	free(s1);
	s1 = ft_strjoin(s2, ".xpm");
	// s1 = ft_strjoin(s2, ".png");
	free(s2);
	free(nbr);
	return (s1);
}

void static load_img(void *mlx, t_images *img)
{
	int w;
	int h;
	char *path = path_img("gwall", 1);

	img->g_wall[0] = mlx_xpm_file_to_image(mlx, path, &w, &h);

	free(path);
}

void init_img(void *mlx, t_images *img)
{
	ft_printf(GREEN "\timages\n");
	ft_printf("%s\n", path_img("gwall", 1));
	load_img(mlx, img);
}
