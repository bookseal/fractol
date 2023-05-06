/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:53:19 by gichlee           #+#    #+#             */
/*   Updated: 2023/05/06 22:48:52 by gichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

void	my_mlx_pixel_put(t_data *img, int column, int lineno, int color)
{
	char	*dst;

	dst = img->addr;
	dst += column * (img->bpp / 8);
	dst += lineno * img->line_len;
	*(unsigned int *)dst = color;
}

int	exit_hook(int keycode, t_data *img)
{
	exit(0);
}

int	key_hook(int keycode, t_data *img)
{
	if (keycode == 53)
		exit_hook(keycode, img);
	return (0);
}

#include <stdio.h>
int	mouse_hook(int mousecode, int x, int y, t_data *img)
{
	if (mousecode == 4 || mousecode == 5)
	{
		// img->zoom *= 1.1;
		// img->is_mandelbrot = 0;
		// FIXME
		mlx_destroy_image(img->mlx, img->img);
		img->img = mlx_new_image(img->mlx, WIN_WIDTH, WIN_HEIGHT);
		img->addr = mlx_get_data_addr(img->img, &(img->bpp), &(img->line_len), &(img->endian));
		draw(img);
	}
	return (0);
}
