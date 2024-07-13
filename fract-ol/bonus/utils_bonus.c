/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osslakri <osslakri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:45:14 by osslakri          #+#    #+#             */
/*   Updated: 2024/06/12 23:50:24 by osslakri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	color_pixel(t_fractol *fractal, int x, int y, int color)
{
	char	*pixel_to_color;

	pixel_to_color = fractal->addr
		+ (y * fractal->depth + (x * fractal->bits_per_pixel / 8));
	*(unsigned int *)pixel_to_color = color;
}

int	destroy_display(t_fractol *fractal, int exit_status)
{
	if (fractal->img)
	{
		mlx_destroy_image(fractal->mlx_ptr, fractal->img);
		fractal->img = NULL;
	}
	if (fractal->win_ptr)
	{
		mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
		fractal->win_ptr = NULL;
	}
	if (fractal->mlx_ptr)
	{
		free(fractal->mlx_ptr);
		fractal->mlx_ptr = NULL;
	}
	exit(exit_status);
	return (0);
}

void	lower_case(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] <= 'Z' && str[i] >= 'A')
			str[i] += 32;
		i++;
	}
}

void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src && src[i] != '\0')
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	lower_case(s1);
	while (s1 && s2 && s1[i] == s2[i] && s1[i] && s2[i])
	{
		++i;
	}
	return (s1[i] - s2[i]);
}
