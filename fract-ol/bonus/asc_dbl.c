/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asc_dbl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osslakri <osslakri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:45:14 by osslakri          #+#    #+#             */
/*   Updated: 2024/06/12 22:55:34 by osslakri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

double	asc_dbl(char *str)
{
	int		sign;
	double	res;
	double	pow;

	(1) && (sign = 1, res = 0, pow = 0.1);
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		++str;
	}
	while (*str >= '0' && *str <= '9')
		(1) && (res *= 10 + *str - 48, ++str);
	if (*str == '.')
	{
		str++;
		while (*str >= '0' && *str <= '9')
		{
			res += (*str - 48) * pow;
			(1) && (pow *= 0.1, ++str);
		}
	}
	return (res * sign);
}
