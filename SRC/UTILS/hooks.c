/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:04:39 by baltes-g          #+#    #+#             */
/*   Updated: 2023/03/12 20:42:05 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INC/headers/fractol.h"

void    zoom_in(t_fractol *fractol, double zoom, double x, double y)
{
    //printf("%f\n", fractol->zoom);
    fractol->zoom *=zoom;
    fractol->base_y *= (HEIGHT + y/HEIGHT)/10;
    fractol->base_x *= (WIDTH + x/WIDTH)/10;
}

void zoom_out(t_fractol *fractol, double zoom, double y, double x)
{
    //printf("%f\n", pow(1.1, -1));
    fractol->zoom *=pow(zoom, -1);
    fractol->base_y -= WIDTH*fractol->zoom/10 * (y/WIDTH);
    fractol->base_x -= HEIGHT*fractol->zoom/10 * (x/HEIGHT);
}

int key_hook(int key_code, t_fractol *fractol)
{
    if (key_code == W)
        fractol->base_y -=20;
    else if (key_code == A)
        fractol->base_x -=20;
    else if (key_code == S)
        fractol->base_y +=20;
    else if (key_code == D)
        fractol->base_x +=20;
    else if (key_code == MODE1)
        fractol->mode = 1;
    else if (key_code == MODE2)
        fractol->mode = 2;
    else if (key_code == MODE3)
        fractol->mode = 3;
    else if (key_code == MODE4)
        fractol->mode = 4;
    else if (key_code == Q)
        zoom_out(fractol, 1.1, 400, 300);
    else if (key_code == E)
        zoom_in(fractol, 1.1, 400, 300);
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