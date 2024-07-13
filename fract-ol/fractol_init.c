/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osslakri <osslakri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:45:14 by osslakri          #+#    #+#             */
/*   Updated: 2024/06/12 22:59:06 by osslakri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	image_initializer(t_fractol *fractal)
{
	fractal->img = mlx_new_image(fractal->mlx_ptr, WIDTH, HEIGHT);
	if (!fractal->img)
	{
		error("Cant't Allocate");
		destroy_display(fractal, 1);
	}
	fractal->addr = mlx_get_data_addr(fractal->img,
			&fractal->bits_per_pixel, &fractal->depth, &fractal->endian);
}
