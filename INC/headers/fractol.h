/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:38:48 by baltes-g          #+#    #+#             */
/*   Updated: 2023/03/11 18:22:19 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define HEIGHT 600
# define WIDTH 800
# define MANDELBROT 0
# define JULIA 1
# define W 13
# define A 0
# define S 1
# define D 2
# define Q 12
# define E 14
# define ESC 53
# define X 17
# define UP 4
# define DOWN 5

typedef struct	s_image {
		void	*img;
		char	*addr;
		int		bits_per_pixel;
		int		line_length;
		int		endian;
}		t_image;

typedef struct s_fractol
{
	int set;
	void	*mlx;
	void	*mlx_win;
	int base_x;
	int base_y;
	int MAX;
	double zoom;
	double juliax;
	double juliay;
	t_image img;
	
}		t_fractol;

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../minilibx_opengl/mlx.h"

int 		error(char *str);
void		mandelbrot(t_fractol *fractol);
void		julia(t_fractol *fractol);
long long	color(int iter, int max);
int			key_hook(int key_code, t_fractol *fractol);
int			mouse_hook(int key_code, int x, int y, t_fractol *fractol);
int			init_fractol(t_fractol *fractol, char **str);
void		my_mlx_pixel_put(t_image *data, int x, int y, int color);
int 		parse(int argc, char **argv);
void    	paint(t_fractol *fractol);

#endif