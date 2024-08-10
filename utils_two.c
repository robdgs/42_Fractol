/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rd-agost <rd-agost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:40:01 by rd-agost          #+#    #+#             */
/*   Updated: 2024/08/07 21:07:36 by rd-agost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 * x window 800x800 [0..799] -> [-2..+2]
 *
 * n = new, o = old, un = unscaled, mn = min, mx = max
 * interpolazione lineare
*/
double	scale(double un_n, double n_mn, double n_mx, double o_mx)
{
	return ((n_mx - n_mn) * (un_n - 0) / (o_mx - 0) + n_mn);
}

t_complex	ft_vector_sum(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

/* 
semplificazione di (x + yi)^2:
componente reale x^2 - y^2
componente immaginaria 2xyi
*/
t_complex	ft_square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = (2 * z.x * z.y);
	return (result);
}
