/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:57:16 by gichlee           #+#    #+#             */
/*   Updated: 2023/05/06 22:49:41 by gichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	draw(t_data *img)
{
	draw_set(img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}

t_data *img_init(void)
{
	t_data	*img;
	
	img = (t_data *)malloc(sizeof(t_data *) * 1);
	img->mlx = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx, WIN_WIDTH, WIN_HEIGHT, "Fractol");	
	img->img = NULL;
	img->addr = NULL;
	img->bpp = 0;
	img->line_len = 0;
	img->endian = 0;
	img->zoom = 1;
	img->is_mandelbrot = 1;
	return (img);
}

int	main(void)
{
	t_data	*img;

	img = img_init();
	img->img = mlx_new_image(img->mlx, WIN_WIDTH, WIN_HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &(img->bpp), &(img->line_len), &(img->endian));
	draw(img);
	mlx_key_hook(img->mlx_win, key_hook, img);
	mlx_hook(img->mlx_win, 4, 0, &mouse_hook, img);
	mlx_hook(img->mlx_win, 17, 0, exit_hook, img);
	mlx_loop(img->mlx);
	free(img);
	return (0);
}
