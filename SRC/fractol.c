/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:49:01 by baltes-g          #+#    #+#             */
/*   Updated: 2023/03/08 18:07:23 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INC/headers/fractol.h"

t_data	img;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	mandelbrot(float Px, float Py)
{
	float x0 = (Px / 800) *2.47 -2;
	float y0 = (Py / 600) * 2.24 -1.12;
	float x;
	float y;

	x = 0;
	y = 0;
	
	int MAX = 400;
	int iter = 0;
	while (x*x + y*y <= 2*2 && iter < MAX)
	{
		float aux = x*x - y*y + x0;
		y = 2*x*y + y0;
		x = aux;
		iter++;
	}
	my_mlx_pixel_put(&img, Px, Py, (iter*0x00FFFFFF)/MAX);
}


int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 600, "Hello world!");
	img.img = mlx_new_image(mlx, 800, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
    for (float i = 0; i < 800; ++i)
        for (float j = 0; j < 600; ++j)
			mandelbrot(i, j);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}