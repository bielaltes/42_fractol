/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:16:14 by baltes-g          #+#    #+#             */
/*   Updated: 2023/03/20 19:48:11 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INC/headers/fractol.h"

int init_fractol(t_fractol *fractol, char **str)
{
    if (ft_strncmp(str[1], "mandelbrot", 0xFFFFFFFF) == 0)
        fractol->set = MANDELBROT;
    else if (ft_strncmp(str[1], "julia", 0xFFFFFFFF) == 0)
    {
        fractol->set = JULIA;
        fractol->juliax = -0.15;
        fractol->juliay = 0.8;
    }
    else
        error("Fractal no disponible");;
    fractol->MAX = 80;
    fractol->mode = 1;
    fractol->color = 0xd7afd7;
    fractol->zoom = 1;
    fractol->base_x = 0.0f;
    fractol->base_y = 0.0f;
    fractol->mlx = mlx_init();
	fractol->mlx_win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, "fract-ol");
	fractol->img.img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	fractol->img.addr = mlx_get_data_addr(fractol->img.img, &(fractol->img.bits_per_pixel),
                            &(fractol->img.line_length), &(fractol->img.endian));
    return (1);
}