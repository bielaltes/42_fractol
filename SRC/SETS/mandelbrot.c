/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:22:38 by baltes-g          #+#    #+#             */
/*   Updated: 2023/03/20 19:47:21 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INC/headers/fractol.h"

static int compute(t_fractol *fractol, double Px, double Py)
{
	double x0 = (( (Px ) / (fractol->zoom * (WIDTH)) + (fractol->base_x))) *2.47 -2;
	double y0 = ((Py ) / (fractol->zoom * (HEIGHT)) + (fractol->base_y)) * 2.24 -1.12;
	double x;
	double y;

	x = 0;
	y = 0;
	
	int iter = 0;
	while (x*x + y*y <= 2*2 && iter < fractol->MAX)
	{
		double aux = x*x - y*y + x0;
		y = 2*x*y + y0;
		x = aux;
		iter++;
	}
    return (iter);
}

void mandelbrot(t_fractol *fractol)
{
    for (int i = 0; i < WIDTH; ++i)
        for (int j = 0; j < HEIGHT; ++j)
			my_mlx_pixel_put(&(fractol->img), i, j, color(compute(fractol, i, j), fractol->MAX, fractol));
    mlx_put_image_to_window(fractol->mlx, fractol->mlx_win, fractol->img.img, 0, 0);
}