/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:49:09 by baltes-g          #+#    #+#             */
/*   Updated: 2023/03/23 12:32:05 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INC/headers/fractol.h"

static void	compute_color1(int iter, int *r, int *g, int *b)
{
	*r = (iter * 3) % 255;
	*g = (iter * 20) % 255;
	*b = (iter * 4) % 255;
}

static void	compute_color2(int iter, int *r, int *g, int *b)
{
	*r = 0xFF - iter;
	if (*r < 0)
		*r *= -1;
	*g = 0xFF - iter;
	if (*g < 0)
		*g *= -1;
	*b = 0xFF - iter;
	if (*b < 0)
		*b *= -1;
}

static void	compute_color3(int iter, int *r, int *g, int *b)
{
	*r = (iter * 40) % 255;
	*g = (int)sqrt(iter);
	*b = ((int)sqrt(iter) * 25) % 255;
}

static void	compute_color4(int iter, int *r, int *g, int *b)
{
	*r = (iter * 12);
	*g = (iter * 8);
	*b = 0xf + (iter * 20);
}

long long	color(int iter, int max, t_fractol *fractol)
{
	int	r;
	int	g;
	int	b;

	if (iter >= max)
		return (0x00000000);
	r = 0xFF;
	g = 0xFF;
	b = 0xFF;
	if (fractol->mode == 1)
		compute_color1(iter, &r, &g, &b);
	else if (fractol->mode == 2)
		compute_color2(iter, &r, &g, &b);
	else if (fractol->mode == 3)
		compute_color3(iter, &r, &g, &b);
	else if (fractol->mode == 4)
		compute_color4(iter, &r, &g, &b);
	return (r << 16 | g << 8 | b);
}
