/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osslakri <osslakri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:45:42 by osslakri          #+#    #+#             */
/*   Updated: 2024/06/13 12:05:18 by osslakri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	window_init(t_fractol *fractal)
{
	fractal->mlx_ptr = mlx_init();
	if (!fractal->mlx_ptr)
	{
		write(1, "Can't Allocate", 14);
		exit(1);
	}
	fractal->win_ptr = mlx_new_window(fractal->mlx_ptr,
			WIDTH, HEIGHT, fractal->name);
	if (!fractal->win_ptr)
	{
		free(fractal->mlx_ptr);
		write(1, "Can't Allocate", 14);
		exit(1);
	}
	if (!ft_strcmp(fractal->name, "mandelbrot"))
		fractal->zoom = 1;
	else
		fractal->zoom = 1.8;
}

void	function1(int ac, char **av, t_fractol *fractol)
{
	if (ac == 2)
	{
		if (!ft_strcmp(av[1], "mandelbrot"))
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
		write(1, "Supported Argument: \"mandelbrot\" or \"julia\" ", 44);
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

int	main(int ac, char **av)
{
	t_fractol	fractol;

	if (ac >= 2 && ac <= 5)
	{
		function1(ac, av, &fractol);
		function2(&fractol);
	}
	else
	{
		write(1, "Usage: ./fractol mandelboart or ./fractol julia", 47);
		exit(0);
	}
	return (0);
}
