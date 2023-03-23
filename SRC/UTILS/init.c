/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:16:14 by baltes-g          #+#    #+#             */
/*   Updated: 2023/03/23 12:21:48 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INC/headers/fractol.h"

int	init_fractol(t_fractol *fractol)
{
	fractol->max = 200;
	fractol->mode = 1;
	fractol->color = 0xd7afd7;
	fractol->zoom = 1;
	fractol->base_x = 0;
	fractol->base_y = 0;
	fractol->mlx = mlx_init();
	if (!fractol->mlx)
		die_error("Could not initialize mlx\n", fractol);
	fractol->mlx_win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, "fract-ol");
	if (!fractol->mlx_win)
		die_error("Could not open a window\n", fractol);
	fractol->img.img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	if (!fractol->img.img)
		die_error("Could not create an image\n", fractol);
	fractol->img.addr = mlx_get_data_addr(fractol->img.img,
			&(fractol->img.bits_per_pixel),
			&(fractol->img.line_length), &(fractol->img.endian));
	if (!fractol->img.addr)
		die_error("Could not get img address\n", fractol);
	return (1);
}

void	re_init(t_fractol *fractol, int fract)
{
	if (fract == M)
		fractol->set = MANDELBROT;
	else if (fract == J)
	{
		fractol->set = JULIA;
		fractol->juliax = -0.15;
		fractol->juliay = 0.8;
	}
	else if (fract == B)
		fractol->set = SHIP;
	fractol->max = 200;
	fractol->zoom = 1;
	fractol->base_x = 0;
	fractol->base_y = 0;
}
