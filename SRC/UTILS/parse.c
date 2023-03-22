/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:04:43 by baltes-g          #+#    #+#             */
/*   Updated: 2023/03/22 18:31:32 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INC/headers/fractol.h"

static int	usage(char *exe)
{
	printf("Error: invalid input\n");
	printf("Usage: %s [mandelbrot burning_ship julia [double double]]\n", exe);
	return (0);
}

void	print_ins(void)
{
	printf("\n    ####    WELCOME TO BALTES-G FRACTOL     ####\n\n");
	printf("    -Scroll to zoom\n");
	printf("    -Change the colors using the numbers [1 .. 4]\n");
	printf("    -Use the arrows to move\n");
	printf("    -Press m, j, b to change fractols\n");
	printf("    -If on julia, change params by clicking\n\n");
}

static void	conf_julia(char **argv, t_fractol *fractol)
{
	fractol->set = JULIA;
	fractol->juliax = double_atoi(argv[2]);
	fractol->juliay = double_atoi(argv[3]);
}

int	parse(int argc, char **argv, t_fractol *fractol)
{
	if (argc == 2)
	{
		if (ft_strncmp(argv[1], "mandelbrot", 0xFFFFFFFF) == 0)
			fractol->set = MANDELBROT;
		else if (ft_strncmp(argv[1], "burning_ship", 0xFFFFFFFF) == 0)
			fractol->set = SHIP;
		else if (ft_strncmp(argv[1], "julia", 0xFFFFFFFF) == 0)
		{
			fractol->set = JULIA;
			fractol->juliax = -0.15;
			fractol->juliay = 0.8;
		}
		else
			return (usage(argv[0]));
	}
	else if (argc == 4 && ft_strncmp(argv[1], "julia", 0xFFFFFFFF) == 0)
	{
		if (!correct_double(argv[2]) || !correct_double(argv[3]))
			return (usage(argv[0]));
		conf_julia(argv, fractol);
	}
	else
		return (usage(argv[0]));
	return (1);
}
