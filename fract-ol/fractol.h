/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osslakri <osslakri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:45:54 by osslakri          #+#    #+#             */
/*   Updated: 2024/06/12 23:03:20 by osslakri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <errno.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <math.h>

# define HEIGHT 1000
# define WIDTH 1000
# define MAX_ITERATION 100
# define REEL_LOWER_LIMIT -2.5
# define REEL_UPPER_LIMIT 1.5 
# define IMAGINARY_LOWER_LIMIT -1.5
# define IMAGINARY_UPPER_LIMIT 1.5

typedef struct complex
{
	double	reel;
	double	imaginary;
}	t_complex;

typedef struct fractal
{
	int			depth;
	int			bits_per_pixel;
	int			endian;
	t_complex	z;
	t_complex	c;
	double		zoom;
	char		name[12];
	double		arg_real;
	double		arg_imaginary;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	char		*addr;
}	t_fractol;

void	calcule_mandelbrot(int x, int y, t_fractol *fractal);
void	calcule_julia(int x, int y, t_fractol *fractal);
void	image_initializer(t_fractol *fractal);
void	render(t_fractol *fractal);
int		keys(int keysym, t_fractol *fractal);
int		mouse(int keysym, int x, int y, t_fractol *fractal);
void	lower_case(char *str);
void	ft_strcpy(char *dest, char *src);
int		ft_strcmp(char *s1, char *s2);
void	color_pixel(t_fractol *fractal, int x, int y, int color);
int		destroy_display(t_fractol *fractal, int exit_status);
void	error(char *message);
double	asc_dbl(char *str);

#endif
