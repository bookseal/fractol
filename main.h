/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:41:35 by gichlee           #+#    #+#             */
/*   Updated: 2023/05/06 22:38:35 by gichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H

# define MAIN_H
# include <mlx.h>
# include <math.h>
# include <stdlib.h>

# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define MAX_ITERATION 20
# define Z_MAX 2

typedef struct s_data {
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	double	zoom;
	int		is_mandelbrot;
}	t_data;

typedef struct s_complex {
	double	real;
	double	imag;
}	t_complex;

void		draw(t_data *img);
void		my_mlx_pixel_put(t_data *img, int column, int lineno, int color);
int			create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b);
void		draw_set(t_data *img);
double		complex_abs(t_complex z);
t_complex	square_complex(t_complex z);
int			exit_hook(int keycode, t_data *img);
int			key_hook(int keycode, t_data *img);
int			mouse_hook(int mousecode, int x, int y, t_data *img);

#endif