/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:09:15 by baltes-g          #+#    #+#             */
/*   Updated: 2023/03/22 18:45:16 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INC/headers/fractol.h"

static int	compute(t_fractol *fractol, double Px, double Py)
{
	double	x;
	double	y;
	int		iter;
	double	aux;

	fractol->x0 = (Px / (WIDTH * fractol->zoom) + fractol->base_x) * 3.5 -2.5;
	fractol->y0 = (Py / (HEIGHT * fractol->zoom) + fractol->base_y) * 2 -1;
	iter = 0;
	x = fractol->x0;
	y = fractol->y0;
	while (x * x + y * y < 4 && iter < fractol->max)
	{
		aux = x;
		x = x * x - y * y + fractol->x0;
		y = fabs(2 * y * aux) + fractol->y0;
		iter++;
	}
	return (iter);
}

void	burning_ship(t_fractol *fractol)
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
