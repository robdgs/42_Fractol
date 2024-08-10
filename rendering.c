/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rd-agost <rd-agost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:45:55 by rd-agost          #+#    #+#             */
/*   Updated: 2024/08/07 20:49:21 by rd-agost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_my_pxput(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bits_pp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static void	mandel_or_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

static void	ft_coord_handl(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = (scale(x, -2, +2, WIDTH) * fractal->zoom) + fractal->shift_x;
	z.y = (scale(y, +2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;
	mandel_or_julia(&z, &c, fractal);
	while (i < fractal->iterations)
	{
		z = ft_vector_sum(ft_square_complex(z), c);
		if ((z.x * z.x) +(z.y * z.y) > fractal->escape_value)
		{
			color = scale(i, MAGENTA, PSYCHEDELIC_PURPLE, fractal->iterations);
			ft_my_pxput(x, y, &fractal->img, color);
			return ;
		}
		i++;
	}
	ft_my_pxput(x, y, &fractal->img, BLACK);
}

void	ft_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (HEIGHT > ++y)
	{
		x = -1;
		while (WIDTH > ++x)
			ft_coord_handl(x, y, fractal);
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,
		fractal->img.img_ptr, 0, 0);
}
