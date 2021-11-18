#include "mlx.h"
#include <stdio.h>

// typedef struct s_data
// {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

// int	main()
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "mlx");
// 	img.img = mlx_new_image(mlx, 1920, 1080);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
// 	while (i < 400)
// 	{
// 		my_mlx_pixel_put(&img, 5, i, 0x0000ff00);
// 		my_mlx_pixel_put(&img, i, 5, 0x00FF0000);
// 		i++;
// 	}
// 	while (j < 400)
// 	{
// 		my_mlx_pixel_put(&img, i, j, 0x00FF0000);
// 		my_mlx_pixel_put(&img, j, i, 0x00FF0000);
// 		j++;
// 	}
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_loop(mlx);
// }

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	key_hook(int keycode, t_vars *vars)
{
	(void)vars;
	printf("%d\n", keycode);
	return (1);
}

int	mouse_hook(int press, t_vars *vars)
{
	(void)vars;
	printf("%d\n", press);
	return (1);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_loop(vars.mlx);
	return (1);
}
