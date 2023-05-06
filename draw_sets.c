/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sets.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:44:14 by gichlee           #+#    #+#             */
/*   Updated: 2023/05/06 21:22:42 by gichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"


int	check_coord_in_mandelbrot_set(double real, double imag)
{
	int			iteration;
	t_complex	z;
	int			color;

	z.real = real;
	z.imag = imag;
	iteration = 0;
	while (complex_abs(z) < Z_MAX && iteration < MAX_ITERATION)
	{
		z = square_complex(z);
		z.real += real;
		z.imag += imag;
		iteration++;
	}
	color = create_trgb(iteration * MAX_ITERATION, 255, 255, 255);
	return (color);
}

int	check_coord_in_julia_set(double real, double imag)
{
	int			iteration;
	t_complex	z;
	int			color;

	z.real = real;
	z.imag = imag;
	iteration = 0;
	while (complex_abs(z) < Z_MAX && iteration < MAX_ITERATION)
	{
		z = square_complex(z);
		z.real += -0.8;
		z.imag += 0.156;
		iteration++;
	}
	color = create_trgb(iteration * MAX_ITERATION, 255, 255, 255);
	return (color);
}

void	draw_set(t_data *img)
{
	int		column;
	int		lineno;
	int		color;
	double	real;
	double	imag;

	lineno = 0;
	while (lineno < WIN_HEIGHT)
	{
		column = 0;
		while (column < WIN_WIDTH)
		{
			real = ((double)column - WIN_WIDTH / 2) / (WIN_WIDTH / 2 / Z_MAX);
			imag = ((double)lineno - WIN_HEIGHT / 2) * Z_MAX * 2 / WIN_HEIGHT;
			// color = check_coord_in_julia_set(real, imag);
			color = check_coord_in_mandelbrot_set(real, imag);
			my_mlx_pixel_put(img, column, lineno, color);
			column++;
		}
		lineno++;
	}
}
