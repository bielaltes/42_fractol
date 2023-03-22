/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:22:26 by baltes-g          #+#    #+#             */
/*   Updated: 2023/03/22 18:35:47 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INC/headers/fractol.h"

void	paint(t_fractol *fractol)
{
	if (fractol->set == MANDELBROT)
		mandelbrot(fractol);
	else if (fractol->set == JULIA)
		julia(fractol);
	else if (fractol->set == SHIP)
		burning_ship(fractol);
}
