/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:04:39 by baltes-g          #+#    #+#             */
/*   Updated: 2023/03/10 20:26:03 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INC/headers/fractol.h"

int key_hook(int key_code, t_fractol *fractol)
{
    if (key_code == W)
        fractol->base_y -=5;
    else if (key_code == A)
        fractol->base_x -=5;
    else if (key_code == S)
        fractol->base_y +=5;
    else if (key_code == D)
        fractol->base_x +=5;
    else if (key_code == Q)
    {
        fractol->zoom -=10;
        fractol->base_x -=5;
        fractol->base_y -=5;
    }
    else if (key_code == E)
    {
        fractol->zoom +=10;
        fractol->base_x +=5;
        fractol->base_y +=5;
    }
    else if (key_code == ESC)
        error("Program escaped");
    paint(fractol);
    return (1);
}

int mouse_hook(int key_code, t_fractol *fractol)
{
    if (key_code == UP)
    {
        fractol->zoom -=10;
        fractol->base_x -=5;
        fractol->base_y -=5;
    }
    else if (key_code == DOWN)
    {
        fractol->zoom +=10;
        fractol->base_x +=5;
        fractol->base_y +=5;
    }
    paint(fractol);
    return(1);
}