/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:04:39 by baltes-g          #+#    #+#             */
/*   Updated: 2023/03/23 12:44:59 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INC/headers/fractol.h"

static void	zoom(t_fractol *fractol, double zoom, double x, double y)
{
	double	x0 ;
	double	y0 ;
	double	x1;
	double	y1;

	x0 = (x / (WIDTH >> 1) - 0.5) / fractol->zoom;
	y0 = (y / (HEIGHT >> 1) - 0.5) / fractol->zoom;
	x1 = (x / (WIDTH >> 1) - 0.5) / (fractol->zoom * zoom);
	y1 = (y / (HEIGHT >> 1) - 0.5) / (fractol->zoom * zoom);
	fractol->base_x += x0 - x1;
	fractol->base_y += y0 - y1;
	fractol->zoom *= zoom;
	if (fractol->max < 350)
		fractol->max += 1;
}

static void	key_hook2(int key_code, t_fractol *fractol)
{
	if (key_code == MODE1)
		fractol->mode = 1;
	else if (key_code == MODE2)
		fractol->mode = 2;
	else if (key_code == MODE3)
		fractol->mode = 3;
	else if (key_code == MODE4)
		fractol->mode = 4;
	else if (key_code == Q)
		zoom(fractol, 0.8, WIDTH / 2, HEIGHT / 2);
	else if (key_code == E)
		zoom(fractol, 1.25, WIDTH / 2, HEIGHT / 2);
	else if (key_code == ESC)
		die_error("Program escaped", fractol);
}

int	key_hook(int key_code, t_fractol *fractol)
{
	if (key_code == UP)
		fractol->base_y -= 0.1 / fractol->zoom;
	else if (key_code == LEFT)
		fractol->base_x -= 0.1 / fractol->zoom;
	else if (key_code == DOWN)
		fractol->base_y += 0.1 / fractol->zoom;
	else if (key_code == RIGHT)
		fractol->base_x += 0.1 / fractol->zoom;
	else if (key_code == M)
		re_init(fractol, M);
	else if (key_code == J)
		re_init(fractol, J);
	else if (key_code == B)
		re_init(fractol, B);
	key_hook2(key_code, fractol);
	paint(fractol);
	return (1);
}

int	mouse_hook(int key_code, int x, int y, t_fractol *fractol)
{
	if (x > 0 && y > 0)
	{
		if (key_code == W_UP)
			zoom(fractol, 0.8, x, y);
		else if (key_code == W_DOWN)
			zoom(fractol, 1.25, x, y);
		else if (key_code == 1 && fractol->set == JULIA)
		{
			fractol->juliax += 0.01 / fractol->zoom;
			fractol->juliay += 0.01 / fractol->zoom;
		}
		else if (key_code == 2 && fractol->set == JULIA)
		{
			fractol->juliax -= 0.01 / fractol->zoom;
			fractol->juliay -= 0.01 / fractol->zoom;
		}
		paint(fractol);
	}
	return (1);
}
