/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osslakri <osslakri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:44:55 by osslakri          #+#    #+#             */
/*   Updated: 2024/06/13 12:05:42 by osslakri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	keys(int keysym, t_fractol *fractal)
{
	if (keysym == 53)
		destroy_display(fractal, 0);
	return (0);
}

int	mouse(int keysym, int x, int y, t_fractol *fractal)
{
	(void)x, (void)y;
	if (keysym == 4)
		fractal->zoom *= 0.3;
	if (keysym == 5)
		fractal->zoom /= 0.3;
	mlx_destroy_image(fractal->mlx_ptr, fractal->img);
	render(fractal);
	return (0);
}

//mlx_ptr = 0x000000010031e230
//fractal->win_ptr = 0x000000010040ab00
// fractal->img = 0x00000001057653d0