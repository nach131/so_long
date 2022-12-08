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

Para instalar la libreria MXL es necesario tener [homebrew](https://brew.sh/) instalar X11 con `brew install Xquartx`.

Ahora ya podemos descomprimir `minilibx_opengl.tgz` e instalarlo.

	cd minilibx_opengl
	make
	sudo cp mlx.h /usr/local/include
	sudo cp libmlx.a /usr/local/lib
	sudo reboot

Instalar man de MLX en MacOs

[minilibx-linux](https://github.com/42Paris/minilibx-linux)

	sudo cp minilibx-linux/man/man3/* /usr/share/man/man3/

## MiniLibX

>`flag`: -lmlx -lXext -lX11
```c
mlx_init ();
```
>`mlx_new_window`      : manage windows

>`mlx_new_image`       : manipulate images

>`mlx_loop`            : handle keyboard or mouse events

```c

```