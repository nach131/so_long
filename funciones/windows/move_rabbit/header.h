
// #include "../../../sources/mlx/mlx_int.h"
#include "../../../sources/mlx/mlx.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../../sources/libft/inc/libft.h"
#include "../../../sources/libft/inc/ft_printf.h"
#include "../../../sources/libft/inc/colors.h"

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

enum
{
	ROCKS,
	GRASS,
	TGREEN,
	DOORC,
	COL,
	ROJO,
};
enum
{
	HERO,
	LOGO,
	MOM,
};

typedef struct s_scp
{
	int x;
	int y;
} t_scp;

typedef struct s_game
{
	void *mlx;
	void *win;
	char *textures[6];
	char *hero[8];
	char *logo[39];
	t_list *mom;
	char **map;
	t_scp enemy;
	int flag;
} t_game;

#define ROWS 6
#define COLS 20

void load_img(t_game *game, char *name, int num, int type);
void load_images(t_game *game);
