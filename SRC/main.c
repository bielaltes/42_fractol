/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:24:39 by baltes-g          #+#    #+#             */
/*   Updated: 2023/03/22 17:34:16 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/headers/fractol.h"

int	error(char *str)
{
	ft_printf("%s\n", str);
	exit(2);
	return (1);
}

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if (parse(argc, argv, &fractol))
	{
		if (!init_fractol(&fractol, argv))
			error("Inalization error");
		print_ins();
		paint(&fractol);
		mlx_key_hook(fractol.mlx_win, key_hook, &fractol);
		mlx_mouse_hook(fractol.mlx_win, mouse_hook, &fractol);
		mlx_hook(fractol.mlx_win, X, 0, error, "Program closed");
		mlx_loop((&fractol)->mlx);
	}
}
