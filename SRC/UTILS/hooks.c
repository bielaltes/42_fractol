/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:04:39 by baltes-g          #+#    #+#             */
/*   Updated: 2023/03/20 20:01:16 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INC/headers/fractol.h"

void    zoom_in(t_fractol *fractol, double zoom, double x, double y)
{

    double	xcalc ;
	double	ycalc ;
	double	new_xcalc;
	double	new_ycalc;

	xcalc = (x - (WIDTH >>2)) / ((WIDTH >> 1) * fractol->zoom);
	ycalc = (y - (HEIGHT >>2)) / ((HEIGHT >> 1) * fractol->zoom);
	new_xcalc = ((x - (WIDTH >>2)) / ((WIDTH >> 1) * fractol->zoom * zoom));
	new_ycalc = ((y - (HEIGHT >>2)) / ((HEIGHT >> 1) * fractol->zoom * zoom));
	fractol->base_x += xcalc - new_xcalc;
	fractol->base_y += ycalc - new_ycalc;
    fractol->zoom *=zoom;
    
    fractol->MAX += 1;
    
}

void zoom_out(t_fractol *fractol, double zoom, double y, double x)
{
    //printf("%f\n", pow(1.1, -1));
    double	xcalc ;
	double	ycalc ;
	double	new_xcalc;
	double	new_ycalc;

	xcalc = (x - (WIDTH >>2)) / ((WIDTH >> 1) * fractol->zoom);
	ycalc = (y - (HEIGHT >>2)) / ((HEIGHT >> 1) * fractol->zoom);
	new_xcalc = ((x - (WIDTH >>2)) / ((WIDTH >> 1) * fractol->zoom / zoom));
	new_ycalc = ((y - (HEIGHT >>2)) / ((HEIGHT >> 1) * fractol->zoom / zoom));
	fractol->base_x += xcalc - new_xcalc;
	fractol->base_y += ycalc - new_ycalc;
    fractol->zoom /=zoom;
    
    fractol->MAX -= 1;
}

int key_hook(int key_code, t_fractol *fractol)
{
    //printf("%f %f \n", fractol->base_x, fractol->base_y);
    if (key_code == W)
        fractol->base_y -=0.1 / fractol->zoom;
    else if (key_code == A)
        fractol->base_x -=0.1 / fractol->zoom;
    else if (key_code == S)
        fractol->base_y +=0.1 / fractol->zoom;
    else if (key_code == D)
        fractol->base_x +=0.1 / fractol->zoom;
    else if (key_code == MODE1)
        fractol->mode = 1;
    else if (key_code == MODE2)
        fractol->mode = 2;
    else if (key_code == MODE3)
        fractol->mode = 3;
    else if (key_code == MODE4)
        fractol->mode = 4;
    else if (key_code == Q)
        zoom_out(fractol, 1.1, WIDTH/2, HEIGHT/2);
    else if (key_code == E)
        zoom_in(fractol, 1.1, WIDTH/2, HEIGHT/2);
    else if (key_code == ESC)
        error("Program escaped");
    paint(fractol);
    return (1);
}

int mouse_hook(int key_code, int x, int y, t_fractol *fractol)
{
    if (x > 0 && y > 0)
    {
        if (key_code == UP)
            zoom_out(fractol, 1.1, x, y);
        else if (key_code == DOWN)
            zoom_in(fractol, 1.1, x, y);
        else if(key_code == 1 && fractol->set == JULIA)
        {
            fractol->juliax += 0.01;
            fractol->juliay += 0.01;
        }
        else if(key_code == 2 && fractol->set == JULIA)
        {
            fractol->juliax -= 0.01;
            fractol->juliay -= 0.01;
        }
        paint(fractol);
    }
    return(1);
}