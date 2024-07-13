/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osslakri <osslakri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:45:14 by osslakri          #+#    #+#             */
/*   Updated: 2024/06/12 23:03:48 by osslakri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	window_init(t_fractol *fractal)
{
	fractal->mlx_ptr = mlx_init();
	if (!fractal->mlx_ptr)
	{
		write(1, "Can't Allocate", 14);
		destroy_display(fractal, 1);
	}
	fractal->win_ptr = mlx_new_window(fractal->mlx_ptr,
			WIDTH, HEIGHT, fractal->name);
	if (!fractal->win_ptr)
	{
		free(fractal->mlx_ptr);
		write(1, "Can't Allocate", 14);
		destroy_display(fractal, 1);
	}
	if (!ft_strcmp(fractal->name, "mandelbrot")
		|| (!ft_strcmp(fractal->name, "burningship")))
		fractal->zoom = 1;
	else
	{
		fractal->zoom = 1.8;
		fractal->c.reel = 0.285;
		fractal->z.imaginary = 0.21;
	}
	(1) && (fractal->shift_x = 0.0, fractal->shift_y = 0.0);
	fractal->color = 0x114ffc;
}

void	function1(int ac, char **av, t_fractol *fractol)
{
	if (ac == 2)
	{
		if (!ft_strcmp(av[1], "mandelbrot"))
			ft_strcpy(fractol->name, av[1]);
		else if (!ft_strcmp(av[1], "burningship"))
			ft_strcpy(fractol->name, av[1]);
	}
	else if (ac == 4)
	{
		if (!ft_strcmp(av[1], "julia"))
		{
			fractol->arg_real = asc_dbl(av[2]);
			fractol->arg_imaginary = asc_dbl(av[3]);
			ft_strcpy(fractol->name, av[1]);
		}
	}
	else
	{
		write(1, "Supported Argument: \"mandelbrot\"", 32);
		write(1, " or \"julia\" or \"burnigship\"", 27);
		exit(1);
	}
}

void	function2(t_fractol *fractol)
{
	window_init(fractol);
	render(fractol);
	mlx_key_hook(fractol->win_ptr, keys, fractol);
	mlx_mouse_hook(fractol->win_ptr, mouse, fractol);
	mlx_hook(fractol->win_ptr, 17, 1L << 17, destroy_display, fractol);
	mlx_loop(fractol->mlx_ptr);
}

int	main(int ac, char *av[])
{
	t_fractol	fractol;

	if (ac >= 2 && ac < 5)
	{
		function1(ac, av, &fractol);
		function2(&fractol);
	}
	else
	{
		write(1, "Usage: ./fractol_bonus mandelboart or ", 38);
		write(1, "./fractol_bonus julia or ./fractol_bonus burningship", 52);
		exit(0);
	}
	return (0);
}
