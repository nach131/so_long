<h1 align="center">
  <img  width="120" alt="42logo"  src="https://user-images.githubusercontent.com/19689770/129336866-169b0dc7-ea41-47d4-b50a-d466508031af.png">
  
	so_long
</h1>
 <p align="center">
<img alt="total-views" src="https://img.shields.io/badge/views-00-blue">
<img alt="total-clone" src="https://img.shields.io/badge/clone-00-blue">
<img alt="GitHub repo size" src="https://img.shields.io/github/repo-size/nach131/so_long">
<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/nach131/so_long">
<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/nach131/so_long">
<img alt="license-MIT" src="https://img.shields.io/badge/license-MIT-blue">
</p>

<h1 align="center">
<!-- ![mapa](so_long.png) -->
</h1>

## instalar MiniLibX en MacOs

Es necesario tener [homebrew](https://brew.sh/)

Instalar X11.

	brew install Xquartx

Ahora ya podemos descomprimir [minilibx_opengl.tgz](https://github.com/nach131/so_long/blob/main/grafic_lib/minilibx_opengl.tgz) e instalarlo.

	cd minilibx_opengl
	make
	sudo cp mlx.h /usr/local/include
	sudo cp libmlx.a /usr/local/lib
	sudo reboot

Instalar man de MLX en MacOs.

[minilibx-linux](https://github.com/42Paris/minilibx-linux)

	sudo cp minilibx-linux/man/man3/* /usr/share/man/man3/

## MiniLibX

Permite crear software gráfico de una manera sencialla y con simples funciones. Permitiendo dibujar y gestionar imagenes con eventos básicos (teclado, ratón).

flag de compilación.

> -lmlx -lXext -lX11

Para inicialiar la conexión entre el software y la pantalla, asignaremos ```mlx_init```, de esta manera se creara una conexión entre la ventana y los evento realiados por el usuario.

```mlx_ptr``` es el parametro identificador devuelto por ```mlx_int()```

```c
void *mlx_init();
```

## mlx_new_window
```c
void	*mlx_new_window ( void *mlx_ptr, int size_x, int size_y, char *title );

int	mlx_clear_window ( void *mlx_ptr, void *win_ptr );

int	mlx_destroy_window ( void *mlx_ptr, void *win_ptr );
```

La función ```mlx_new_window()``` crea una nueva ventana en la pantalla, utilizando los parametros ```size_x``` y ```size_y``` para determinar el tamaño y `*title` para el título de la ventana.

```mlx_new_window()``` devuelve un indicador de ventana ```void *``` que se pude usar con otras llamadas de MiniLibX, ya que la libreria puede usar un numero arbitrario de ventanas separadas.

`mlx_clear_window() `y `mlx_destroy_window()` respectivamente limpian (en negro) y destruyen la ventana dada.

`mlx_ptr` es el identificador de conexión de pantalla y `win_ptr` es un identificador de ventana.




>`mlx_new_image`       : manipulate images

>`mlx_loop`            : handle keyboard or mouse events

```c

```