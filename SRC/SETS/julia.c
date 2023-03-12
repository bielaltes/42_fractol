/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 19:38:41 by baltes-g          #+#    #+#             */
/*   Updated: 2023/03/12 19:18:29 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INC/headers/fractol.h"

static int compute(t_fractol *fractol, double Px, double Py)
{
    double x0 = ((Px + fractol->base_x) / (WIDTH * fractol->zoom)) * 4 -2;
	double y0 = ((Py + fractol->base_y)/ (HEIGHT * fractol->zoom)) * 4 -2;
	
	int iter = 0;
	//ft_printf("%d\n", x0*x0 + y0*y0);
	while (x0*x0 + y0*y0 < 4 && iter < fractol->MAX)
	{
		double aux = x0*x0 - y0*y0 + fractol->juliax;
		y0 = 2*x0*y0 + fractol->juliay;
		x0 = aux;
		iter++;
	}
    return (iter);
}

void julia(t_fractol *fractol)
{
    for (int i = 0; i < WIDTH; ++i)
        for (int j = 0; j < HEIGHT; ++j)
			my_mlx_pixel_put(&(fractol->img), i, j, color(compute(fractol, i, j), fractol->MAX, fractol));
    mlx_put_image_to_window(fractol->mlx, fractol->mlx_win, fractol->img.img, 0, 0);
}