<h1 align="center">
  <img  width="120" alt="42logo"  src="https://user-images.githubusercontent.com/19689770/129336866-169b0dc7-ea41-47d4-b50a-d466508031af.png">
  
	so_long
</h1>

 <p align="center">
<img alt="total-views" src="https://img.shields.io/badge/views-70-blue">
<img alt="total-clone" src="https://img.shields.io/badge/clone-95-blue">
<img alt="GitHub repo size" src="https://img.shields.io/github/repo-size/nach131/so_long">
<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/nach131/so_long">
<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/nach131/so_long">
<img alt="license-MIT" src="https://img.shields.io/badge/license-MIT-blue">
</p>

<span align="center">

![visitors](https://visitor-badge.glitch.me/badge?page_id=nach131.so_long&left_color=green&right_color=blue)

![125](https://github.com/nach131/42Barcelona/blob/main/images/125.png)

![gif](https://github.com/nach131/so_long/blob/doble-puntero/gif/so_long.gif)

</span>


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

<h1 align="center">

![utilizadas](https://github.com/nach131/so_long/blob/doble-puntero/utilizadas.png)

</h1>

Permite crear software gráfico de una manera sencilla y con simples funciones. Permitiendo dibujar y gestionar imagenes con eventos básicos (teclado, ratón).

flag de compilación.

> -framework OpenGL -framework AppKit

Para inicialiar la conexión entre el software y la pantalla, asignaremos ```mlx_init```, de esta manera se creara una conexión entre la ventana y los evento realiados por el usuario.

```mlx_ptr``` es el argumento identificador devuelto por ```mlx_int()```

```c
void *mlx_init();
```

## mlx_new_window
```c
void	*mlx_new_window ( void *mlx_ptr, int size_x, int size_y, char *title );

int	mlx_clear_window ( void *mlx_ptr, void *win_ptr );

int	mlx_destroy_window ( void *mlx_ptr, void *win_ptr );
```

La función ```mlx_new_window()``` crea una nueva ventana en la pantalla, utilizando los argumtos ```size_x``` y ```size_y``` para determinar el tamaño y `*title` para el título de la ventana.

```mlx_new_window()``` devuelve un indicador de ventana ```void *``` que se pude usar con otras llamadas de MiniLibX, ya que la libreria puede usar un numero arbitrario de ventanas separadas.

`mlx_clear_window() `y `mlx_destroy_window()` respectivamente limpian (en negro) y destruyen la ventana.

`mlx_ptr` es el identificador de la conexión y `win_ptr` es un identificador de ventana.


<!-- ### mlx_new_image()
```c
void	*mlx_new_image ( void *mlx_ptr, int width, int height );
```
Pone una imagen en la memoria, devolviendo un puntero, para poder procesar la imagen, necesita el tamaño de la imagen y el conector de `mlx_ptr` -->

### XPM images

```c
void	*mlx_xpm_file_to_image ( void *mlx_ptr, char *filename, int *width, int *height );
```

Devuelve el puntero de la estructura `"mlx_img_list_t"` en la cual esta un char puntero con los datos del archivo xpm que le hemos pasado en `"filename"`.


### mlx_put_image_to_window

```c
int	mlx_put_image_to_window ( void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y );
```
La imagen almacenada se podra mostrar en cualquier ventana especificando el identificador de la conexión, la ventana y la imagen `(mlx_ptr, win_ptr, and img_ptr)` son necesarios las cordenadas x, y para definir donde debe colocarse la imagen.

<!-- ### mlx_get_data_addr()
```c
char	*mlx_get_data_addr ( void *img_ptr, int *bits_per_pixel, int *size_line, int *endian );
```
Devuelve información sobre la imagen para poder ser manipulada, `img_ptr` especifica la imagen a usar.

`bits_per_pixel` se llenara con el número de bits necesarios para representrar un color de pixel.

`size_line` es el número de bytes necesarios para almacenar una línea de la imagen en la memoria, es necesario para poder moverse de una línea a otra en la imagen.

`endian` el color de pixel de la imagen debe almacenarse en little endian (endian == 0) o big endian (endian == 1)

Devuelve una dirección de `char *` que representa el comienzo del área de momoria dende se almacena la imagen.

Apartir de esta dirección, los primeros `bits_per_pixel` representan el color del primer pixel en la primera linea de la imagen.

El segundo grupo de `bits_per_pixel` representan el segundo pixel de la primera línea y asi... -->

### int	mlx_destroy_image()

Si vamos a volver a utilizar la variable donde se ha guardado el archivo xpm, es necesario liberar esa varible con `mlx_destroy_image`.

```c
int	mlx_destroy_image ( void *mlx_ptr, void *img_ptr );
```
Destruye la imagen pasada por `img_ptr` y livera la variable.

## Eventos

Para controlar los eventos, utilizaremos `mlx_hook`, MiniLibx utiliza los eventos de la libreria X11, podemos saber mas sobre ellos en el siguiente enlace.

[Tipos de eventos](https://tronche.com/gui/x/xlib/events/types.html)

Una lista con todos los evento y las mascaras para utilizar en el siguiente enlace:

[42Doc](https://harm-smits.github.io/42docs/libs/minilibx/events.html)


```c
void mlx_hook(mlx_win_list_t *win_ptr, int x_event, int x_mask, int (*funct_ptr)(), void *param)
```

`win_ptr` Identificador de la wentana a controlar.

`x_event` El evento a controlar.

`x_mask` La mascara para el evento a controlar,

`funct_ptr` La función que se ejecutara cuendo el evento se active.

`param` Parametros que se le pasaran a la función a ejecutar.

Yo solo he utilizado el evento "17" `DestroyNotify` que controla el click de cerrar la venta.

con la función `exit` casteada en void, y `NULL` como parametro ya que exit no necesita.

```c
mlx_hook(game.win, 17, 1L << 0, (void *)exit, NULL);
```
Para controlar las teclas pulsadas por el usuario

```c
void mlx_key_hook(mlx_win_list_t *win_ptr, int (*funct_ptr)(), void *param)

mlx_key_hook(game->graphic.win, key_hook, game);
```

En mi caso yo paso la funcion `key_hook`, que recibe el parametro `game` pasado mediante la función `mlx_key_hook` y recibe `keycode` que es el numero de tecla pulsado.

```c
int	key_hook(int keycode, t_game *game)
```

## Animaciones

Para conseguir las animaciones utililzo el loop `mlx_loop_hook`

```c
int mlx_loop_hook(mlx_ptr_t *mlx_ptr, void (*fct)(void *), void *param)
```

## mlx_loop

Para que la libreria MiniLibX funcione es necesario poner como ultima función `mlx_loop`

```c
void mlx_loop(mlx_ptr_t *mlx_ptr)
```

<!-- ### mlx_get_color_value()
```c
unsigned int	mlx_get_color_value ( void *mlx_ptr, int color );
```
Para control el color de píxel, (no lo uso). -->

## Convertir png a xpm en linux

	sudo apt install imagemagick

	convert a.png x.xpm
	convert x.xpm aa.png

Mejorando la calidad y definiendo cantidad de colores

	convert fotograma-000001.png -depth 8 -colors 256 -colorspace RGB -define XPM:color-format='6c' -define XPM:sort=True -define XPM:string=1 -define XPM:mime=1 fotograma-000001.xpm

<!-- 
para toda una carpeta
	 for file in *.png; do convert  $file $file.xpm; done
	 for f in */*.bmp ; do convert $f ${f%bmp}png;
 done -->

## Carpeta de png

Para convertir a xpm todos los png que hay en una carpeta

	for file in *.png; do convert $file -depth 8 -colors 256 -colorspace RGB -define XPM:color-format='6c' -define XPM:sort=True -define XPM:string=1 -define XPM:mime=1 $file.xpm; done

## para mac

	$ brew info imagemagick
	$ brew install imagemagick

https://imagemagick.org/script/download.php
