
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
	char *hero[4];
	char *logo[40];
	char *mom[4];
	char **map;
	t_scp enemy;
} t_game;

#define ROWS 6
#define COLS 20
