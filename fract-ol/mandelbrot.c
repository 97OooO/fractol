/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osslakri <osslakri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:44:55 by osslakri          #+#    #+#             */
/*   Updated: 2024/06/12 22:59:06 by osslakri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calcule_mandelbrot(int x, int y, t_fractol *fractal)
{
	int		it[2];
	double	temp;

	fractal->c.reel = REEL_LOWER_LIMIT
		+ (x * (fabs(REEL_LOWER_LIMIT - REEL_UPPER_LIMIT) / WIDTH))
		* fractal->zoom;
	fractal->c.imaginary = IMAGINARY_UPPER_LIMIT
		- (y * (fabs(IMAGINARY_UPPER_LIMIT - IMAGINARY_LOWER_LIMIT) / HEIGHT))
		* fractal->zoom;
	(1) && (fractal->z.reel = 0, fractal->z.imaginary = 0,
			it[1] = 0, it[0] = 0);
	while (it[0]++ < MAX_ITERATION && !it[1])
	{
		temp = fractal->z.reel * fractal->z.reel
			- fractal->z.imaginary * fractal->z.imaginary + fractal->c.reel;
		fractal->z.imaginary = 2 * fractal->z.reel
			* fractal->z.imaginary + fractal->c.imaginary;
		fractal->z.reel = temp;
		(sqrt(fractal->z.reel * fractal->z.reel + fractal->z.imaginary
				* fractal->z.imaginary) > 2.0) && (it[1] = 1);
	}
	if (!it[1])
		color_pixel(fractal, x, y, 0x000000);
	else
		color_pixel(fractal, x, y, 0xff1800 * it[0]);
}
