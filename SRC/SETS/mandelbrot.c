/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:22:38 by baltes-g          #+#    #+#             */
/*   Updated: 2023/03/22 18:44:41 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INC/headers/fractol.h"

static int	compute(t_fractol *f, double Px, double Py)
{
	double	x;
	double	y;
	double	aux;
	int		iter;

	iter = 0;
	x = 0;
	y = 0;
	f->x0 = (Px / (f->zoom * WIDTH) + (f->base_x)) * 2.47 -2;
	f->y0 = (Py / (f->zoom * HEIGHT) + (f->base_y)) * 2.24 -1.12;
	while (x * x + y * y <= 2 * 2 && iter < f->max)
	{
		aux = x * x - y * y + f->x0;
		y = 2 * x * y + f->y0;
		x = aux;
		iter++;
	}
	return (iter);
}

void	mandelbrot(t_fractol *fractol)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			my_mlx_pixel_put(&(fractol->img), i, j,
				color(compute(fractol, i, j), fractol->max, fractol));
			++j;
		}
		++i;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->mlx_win,
		fractol->img.img, 0, 0);
}
