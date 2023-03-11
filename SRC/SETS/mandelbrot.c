/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:22:38 by baltes-g          #+#    #+#             */
/*   Updated: 2023/03/11 18:46:44 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INC/headers/fractol.h"

static int compute(t_fractol *fractol, float Px, float Py)
{
    float x0 = ((Px + fractol->base_x) / (WIDTH * fractol->zoom)) *2.47 -2;
	float y0 = ((Py + fractol->base_y)/ (HEIGHT * fractol->zoom)) * 2.24 -1.12;
	float x;
	float y;

	x = 0;
	y = 0;
	
	int iter = 0;
	while (x*x + y*y <= 2*2 && iter < fractol->MAX)
	{
		float aux = x*x - y*y + x0;
		y = 2*x*y + y0;
		x = aux;
		iter++;
	}
    return (iter);
}

void mandelbrot(t_fractol *fractol)
{
    for (float i = 0; i < 800; ++i)
        for (float j = 0; j < 600; ++j)
			my_mlx_pixel_put(&(fractol->img), i, j, color(compute(fractol, i, j), fractol->MAX));
    mlx_put_image_to_window(fractol->mlx, fractol->mlx_win, fractol->img.img, 0, 0);
}