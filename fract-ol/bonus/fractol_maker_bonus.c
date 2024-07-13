/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_maker_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osslakri <osslakri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:45:14 by osslakri          #+#    #+#             */
/*   Updated: 2024/06/12 22:59:06 by osslakri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	render(t_fractol *fractal)
{
	int	x;
	int	y;

	y = 0;
	image_initializer(fractal);
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (!ft_strcmp(fractal->name, "mandelbrot"))
				calcule_mandelbrot(x, y, fractal);
			else if (!ft_strcmp(fractal->name, "burningship"))
				calcule_burningship(x, y, fractal);
			else if (!ft_strcmp(fractal->name, "julia"))
				calcule_julia(x, y, fractal);
			else
				destroy_display(fractal, 1);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_ptr,
		fractal->win_ptr, fractal->img, 0, 0);
}
