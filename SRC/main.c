/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:24:39 by baltes-g          #+#    #+#             */
/*   Updated: 2023/03/09 18:12:15 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/headers/fractol.h"

void error(char *str)
{
    perror(str);
    exit(2);
}

int main(int argc, char **argv)
{
    t_fractol fractol;

    if (parse(argc, argv))
    {
        if (!init_fractol(&fractol, argv))
            error("Inalization error");
        mandelbrot(&fractol);
        mlx_key_hook(fractol.mlx_win, key_hook, &fractol);
        mlx_loop((&fractol)->mlx);
    }
    else
    {
        ft_printf("Input error\n");
    }
}