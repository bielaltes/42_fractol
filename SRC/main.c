/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:24:39 by baltes-g          #+#    #+#             */
/*   Updated: 2023/03/23 13:08:37 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/headers/fractol.h"

int	die_error(char *str, t_fractol *fractol)
{
	ft_printf("%s\n", str);
	if (fractol->mlx && fractol->img.img)
		mlx_destroy_image(fractol->mlx, fractol->img.img);
	if (fractol->mlx && fractol->mlx_win)
		mlx_destroy_window(fractol->mlx, fractol->mlx_win);
	exit(2);
	return (1);
}

static int	close_x(t_fractol *fractol)
{
	ft_printf("Program closed\n");
	if (fractol->mlx && fractol->img.img)
		mlx_destroy_image(fractol->mlx, fractol->img.img);
	if (fractol->mlx && fractol->mlx_win)
		mlx_destroy_window(fractol->mlx, fractol->mlx_win);
	exit(2);
	return (1);
}

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if (parse(argc, argv, &fractol))
	{
		if (!init_fractol(&fractol))
			die_error("Initialization error", &fractol);
		print_ins();
		paint(&fractol);
		mlx_key_hook(fractol.mlx_win, key_hook, &fractol);
		mlx_mouse_hook(fractol.mlx_win, mouse_hook, &fractol);
		mlx_hook(fractol.mlx_win, X, 0, close_x, &fractol);
		mlx_loop((&fractol)->mlx);
	}
}
