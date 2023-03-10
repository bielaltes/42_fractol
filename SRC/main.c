/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:24:39 by baltes-g          #+#    #+#             */
/*   Updated: 2023/03/10 20:26:38 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/headers/fractol.h"

int error(char *str)
{
    ft_printf("%s\n", str);
    exit(2);
    return (1);
}

int main(int argc, char **argv)
{
    t_fractol fractol;

    if (parse(argc, argv))
    {
        if (!init_fractol(&fractol, argv))
            error("Inalization error");
        paint(&fractol);
        mlx_key_hook(fractol.mlx_win, key_hook, &fractol);
        mlx_mouse_hook(fractol.mlx_win, mouse_hook, &fractol);
        mlx_hook(fractol.mlx_win, X, 0, error, "Program escaped");
        mlx_loop((&fractol)->mlx);
    }
    else
    {
        ft_printf("Input error\n");
    }
}