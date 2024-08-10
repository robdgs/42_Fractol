/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rd-agost <rd-agost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 12:01:22 by rd-agost          #+#    #+#             */
/*   Updated: 2024/08/07 21:18:55 by rd-agost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <X11/X.h>
# include <X11/Xlib.h>
# include <X11/keysym.h>
# include <math.h>
# include "minilibx-linux/mlx.h"

# define ERROR_MSG "Input errato, scegli un frattale"
# define HEIGHT 700
# define WIDTH 700

# define BLACK       0x000000
# define WHITE       0xFFFFFF
# define RED         0xFF0000
# define BLUE        0x0000FF
# define MAGENTA   0xFF00FF
# define LIME_SHOCK      0xCCFF00
# define NEON_ORANGE     0xFF6600
# define PSYCHEDELIC_PURPLE 0x660066
# define AQUA_DREAM      0x33CCCC
# define HOT_PINK        0xFF66B2
# define ELECTRIC_BLUE   0x0066FF
# define LAVA_RED        0xFF3300

/* 
	PIXEL BUFFER AKA IMAGE
	- values fom mlx_get_data_addr()
	- ptr to image struct
	- ptr that will be used to change pixels in our img
		(points to the actual pixels)
	- bits per pixel
*/
typedef struct s_img
{
	void		*img_ptr;
	char		*pixels_ptr;
	int			bits_pp;
	int			endian;
	int			line_len;
}				t_img;

/* 
	FRACTAL ESSENTIALS 
	- ptr coming from mlx_init()
	- ptr coming from mlx_new_window()
	- image perche' px by px anche no
	- hooks values
*/
typedef struct s_fractal
{
	char		*name;
	void		*mlx_connection;
	void		*mlx_window;
	t_img		img;
	double		escape_value;
	int			iterations;
	double		shift_x;
	double		shift_y;
	double		zoom;
	double		julia_x;
	double		julia_y;
}			t_fractal;

/*
	COMPLEX NUM
*/
typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

// utils_one.c
int			ft_strncmp(char *s1, char *s2, size_t n);
void		putstr_fd(char *s, int fd);
int			ft_strlen(char *s);
double		ft_atodbl(char *s);

//utils_two.c
double		scale(double un_n, double n_mn, double n_mx, double o_mx);
t_complex	ft_vector_sum(t_complex z1, t_complex z2);
t_complex	ft_square_complex(t_complex z);

//init.c
void		ft_fractal_init(t_fractal *fractal);

//rendering.c
void		ft_render(t_fractal *fractal);

//event_listeners.c
int			ft_key_handler(int keysym, t_fractal *fractal);
int			ft_close_handler(t_fractal *fractal);
int			ft_mouse_handler(int button, int x, int y, t_fractal *fractal);
int			ft_julia_track(int x, int y, t_fractal *fractal);

#endif