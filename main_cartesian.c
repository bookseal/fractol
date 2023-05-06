/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_cartesian.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 18:02:42 by gichlee           #+#    #+#             */
/*   Updated: 2023/05/05 16:55:29 by gichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdlib.h>
#include <math.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		height;
	int		width;
}				t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	my_mlx_pixel_put_on_cartesian(t_data *data, int x, int y, int color)
{
	char	*dst;
	int		x_zero;
	int		y_zero;

	x_zero = data->width / 2;
	y_zero = data->height / 2;
	dst = data->addr + ((y_zero - y) * data->line_length + (x_zero + x) * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_square(t_data *img, int x, int y, int len_side)
{
	int	idx;
	int	color;

	color = 0x00FF0000;
	idx = 0;
	while (idx < len_side)
		my_mlx_pixel_put(img, x + idx++, y, color);
	idx = 0;
	while (idx < len_side)
		my_mlx_pixel_put(img, x + len_side, y + idx++, color);
	idx = 0;
	while (idx < len_side)
		my_mlx_pixel_put(img, x + len_side - idx++, y + len_side, color);
	idx = 0;
	while (idx < len_side)
		my_mlx_pixel_put(img, x, y + len_side - idx++, color);
}

void	draw_right_triangle(t_data *img, int x, int y, int len_legs)
{
	int	idx;
	int	color;
	int	curr_x;
	int	curr_y;

	color = 0x00FF0000;
	curr_x = x;
	curr_y = y;
	idx = 0;
	while (idx < len_legs)
	{
		curr_x++;
		curr_y++;
		my_mlx_pixel_put(img, curr_x, curr_y, color);
		idx++;
	}
	idx = 0;
	while (idx < len_legs)
	{
		curr_x--;
		my_mlx_pixel_put(img, curr_x, curr_y, color);
		idx++;
	}
	idx = 0;
	while (idx < len_legs)
	{
		curr_y--;
		my_mlx_pixel_put(img, curr_x, curr_y, color);
		idx++;
	}
}

void	draw_2_dimensional_axis(t_data *img, int width, int height)
{
	int	idx;
	int	color;

	color = 0xFFFFFF00;
	idx = 0;
	while (idx < width)
		my_mlx_pixel_put(img, idx++, height / 2, color);
	idx = 0;
	while (idx < height)
		my_mlx_pixel_put(img, width / 2, idx++, color);
}

void	draw_linear_equation(t_data *img, int width, int height, int a, int b)
{
	int	color;
	int	x;
	int	y;

	color = 0x00FF0000;
	x = width / 2 - 150;
	while (x < width / 2 + 150)
	{
		x++;
		y = height / 2 - a * (x - width / 2) - b;
		my_mlx_pixel_put(img, x, y, color);
	}
}

void	draw_quadratic_equation(t_data *img, double a, double p, double q)
{
	int	x;
	int	color;

	color = 0x00FF0000;
	x = -100;
	while (x < 100)
	{
		my_mlx_pixel_put_on_cartesian(img, x, a * (x - p) * (x - p) + q, color);
		x++;
	}
}

void	draw_circle(t_data *img, int rad)
{
	int	x;
	int	color;
	int	y;

	color = 0x00FF0000;
	x = -1 * rad;
	while (x < rad)
	{
		y = (int)sqrt(abs(x * x - rad * rad));
		my_mlx_pixel_put_on_cartesian(img, x, y, color);
		my_mlx_pixel_put_on_cartesian(img, x, -1 * y, color);
		x++;
	}
}

int	deal_key(int key, t_vars *vars)
{
	printf("%d\n", key);
	if (key == 53)
		exit(1);
	if (key == 126)
		printf("up pressed\n");
		up(vars);
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_vars	vars;
	int		height;
	int		width;

	height = 800;
	width = 800;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, width, height, "hello");
	img.img = mlx_new_image(vars.mlx, width, height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	&img.line_length, &img.endian);
	img.width = width;
	img.height = height;
	draw_square(&img, 100, 100, 50);
	draw_right_triangle(&img, 200, 100, 50);
	draw_2_dimensional_axis(&img, width, height);
	draw_linear_equation(&img, width, height, -2, -150);
	draw_quadratic_equation(&img, 0.02, 30, 50);
	draw_circle(&img, 20);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_key_hook(vars.win, deal_key, (void *)0);
	mlx_loop(vars.mlx);
	return (0);
}
