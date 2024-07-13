/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_events_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osslakri <osslakri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:45:14 by osslakri          #+#    #+#             */
/*   Updated: 2024/06/12 22:59:06 by osslakri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	keys(int fleches, t_fractol *fractal)
{
	unsigned int	color;

	if (fleches == 53)
		destroy_display(fractal, 0);
	else if (fleches == 123)
		fractal->shift_x += (0.1337 * fractal->zoom);
	else if (fleches == 124)
		fractal->shift_x -= (0.1337 * fractal->zoom);
	else if (fleches == 126)
		fractal->shift_y -= (0.1337 * fractal->zoom);
	else if (fleches == 125)
		fractal->shift_y += (0.1337 * fractal->zoom);
	else if (fleches == 49)
	{
		color = fractal->color * 1.337;
		if (color == 0)
			color = fractal->color;
		fractal->color = color;
	}
	mlx_destroy_image(fractal->mlx_ptr, fractal->img);
	render(fractal);
	return (0);
}

int	mouse(int roulette, int x, int y, t_fractol *fractal)
{
	(void)x, (void)y;
	if (roulette == 4)
		fractal->zoom *= 1.337;
	if (roulette == 5)
		fractal->zoom /= 1.337;
	mlx_destroy_image(fractal->mlx_ptr, fractal->img);
	render(fractal);
	return (0);
}
