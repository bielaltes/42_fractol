/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:38:48 by baltes-g          #+#    #+#             */
/*   Updated: 2023/03/23 12:22:04 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define HEIGHT 750
# define WIDTH 1000
# define MANDELBROT 0
# define JULIA 1
# define SHIP 2
# define LEFT 123
# define UP 126
# define DOWN 125
# define RIGHT 124
# define B 11
# define M 46
# define J 38
# define Q 12
# define E 14
# define ESC 53
# define X 17
# define W_UP 4
# define W_DOWN 5
# define MODE1 18
# define MODE2 19
# define MODE3 20
# define MODE4 21

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"
# include "../minilibx_opengl/mlx.h"

typedef struct s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_image;

typedef struct s_fractol
{
	int			set;
	int			mode;
	void		*mlx;
	void		*mlx_win;
	double		base_x;
	double		base_y;
	int			max;
	double		zoom;
	double		x0;
	double		y0;
	double		juliax;
	double		juliay;
	long long	color;
	t_image		img;
}		t_fractol;

int			die_error(char *str, t_fractol *fractol);
void		mandelbrot(t_fractol *fractol);
void		julia(t_fractol *fractol);
void		burning_ship(t_fractol *fractol);
long long	color(int iter, int max, t_fractol *fractol);
int			key_hook(int key_code, t_fractol *fractol);
int			mouse_hook(int key_code, int x, int y, t_fractol *fractol);
int			init_fractol(t_fractol *fractol);
void		my_mlx_pixel_put(t_image *data, int x, int y, int color);
int			parse(int argc, char **argv, t_fractol *fractol);
void		paint(t_fractol *fractol);
void		print_ins(void);
void		re_init(t_fractol *fractol, int fract);
double		double_atoi(char *str);
int			correct_double(char *str);

#endif