/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:04:39 by baltes-g          #+#    #+#             */
/*   Updated: 2023/03/11 19:00:37 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INC/headers/fractol.h"

void    zoom_in(t_fractol *fractol, double zoom, double x, double y)
{
    fractol->zoom *=zoom;
    fractol->base_x += WIDTH*fractol->zoom/10 / (WIDTH/x);
    fractol->base_y += HEIGHT*fractol->zoom/10 / (HEIGHT/y);

}

void zoom_out(t_fractol *fractol, double zoom, double y, double x)
{
    fractol->zoom /=zoom;
    fractol->base_x -= WIDTH*fractol->zoom/10 / (WIDTH/x);
    fractol->base_y -= HEIGHT*fractol->zoom/10 / (HEIGHT/y);
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
    ft_printf("%d %d\n", x, y);
    if (key_code == UP)
        zoom_out(fractol, 1.1, x, y);
    else if (key_code == DOWN)
        zoom_in(fractol, 1.1, x, y);
    else if(key_code == 1 && fractol->set == JULIA)
    {
        fractol->juliax = WIDTH /x;
        fractol->juliay = HEIGHT /y;
    }
    paint(fractol);
    return(1);
}