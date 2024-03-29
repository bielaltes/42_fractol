/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 19:38:41 by baltes-g          #+#    #+#             */
/*   Updated: 2023/03/22 18:45:12 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INC/headers/fractol.h"

static int	compute(t_fractol *fractol, double Px, double Py)
{
	int		iter;
	double	aux;
	double	x0;
	double	y0;

	iter = 0;
	x0 = (Px / (WIDTH * fractol->zoom) + fractol->base_x) * 4 -2;
	y0 = (Py / (HEIGHT * fractol->zoom) + fractol->base_y) * 4 -2;
	while (x0 * x0 + y0 * y0 < 4 && iter < fractol->max)
	{
		aux = x0 * x0 - y0 * y0 + fractol->juliax;
		y0 = 2 * x0 * y0 + fractol->juliay;
		x0 = aux;
		iter++;
	}
	return (iter);
}

void	julia(t_fractol *fractol)
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
