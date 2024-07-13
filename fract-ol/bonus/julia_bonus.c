/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osslakri <osslakri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:45:14 by osslakri          #+#    #+#             */
/*   Updated: 2024/06/13 12:06:37 by osslakri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	calcule_julia(int x, int y, t_fractol *f)
{
	int		it;
	int		point_outside;
	double	temp;

	f->z.reel = REEL_LOWER_LIMIT + (x * (fabs(REEL_LOWER_LIMIT
					- REEL_UPPER_LIMIT) / WIDTH)) * f->zoom + f->shift_x;
	f->z.imaginary = IMAGINARY_UPPER_LIMIT - (y * (fabs(IMAGINARY_UPPER_LIMIT
					- IMAGINARY_LOWER_LIMIT) / HEIGHT)) * f->zoom + f->shift_y;
	(1) && (point_outside = 0, it = 0);
	while (it++ < MAX_ITERATION && !point_outside)
	{
		temp = f->z.reel * f->z.reel
			- f->z.imaginary * f->z.imaginary + f->arg_real;
		f->z.imaginary = 2 * f->z.reel
			* f->z.imaginary + f->c.imaginary
			+ f->arg_imaginary;
		f->z.reel = temp;
		if (sqrt(f->z.reel * f->z.reel
				+ f->z.imaginary * f->z.imaginary) > 2.0)
			point_outside = 1;
	}
	if (!point_outside)
		color_pixel(f, x, y, 0x000000);
	else
		color_pixel(f, x, y, (*f).color * it);
}
