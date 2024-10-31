/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:47:24 by matle-br          #+#    #+#             */
/*   Updated: 2024/10/31 16:00:52 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <sys/time.h>
# include <signal.h>

/*  Dimensions	*/
# define WIDTH		800
# define HEIGHT		800
# define X_MIN		-2.5
# define X_MAX		1.5
# define Y_MIN		-2.0
# define Y_MAX		2.0
# define X1_MIN		-2.0
# define X1_MAX		2.0
# define Y1_MIN		-2.0
# define Y1_MAX		2.0
# define XK_MIN		65453
# define XK_PLUS	65451

/* COULEURS */

# define NOIR 0x000000
# define BLANC 0xFFFFFF

/* COULEURS  PSYCHEDELIQUES*/

# define MAGENTA_VIF 0xFF00FF
# define CYAN_VIF 0x00FFFF
# define ORANGE_VIF 0xFF6600
# define VERT_VIF 0x00FF00
# define ROUGE_VIF 0xFF0000
# define JAUNE_VIF 0xFFFF00
# define ROSE_VIF 0xFF00AA
# define TURQUOISE_VIF 0x00FFAA
# define ORANGE_ROUGEATRE 0xFF5500
# define BLEU_ELECTRIQUE 0x00AAFF
# define BLEU_ROYALE 0x0033AA

/* Welcome Message */

# define FIRST_SENTENCE "Welcome, this is a manual on how you can modify \
this project with the keyboard!"

# define SECOND_SENTENCE "1 -> First, you can use the four arrows to move."

# define THIRD_SENTENCE "2 -> Then, you can use the \
mouse wheel to zoom / dezoom."

# define FOURTH_SENTENCE "3 -> You can press the buttons '+' / '-' to increase / decrease  \
the precision."

# define FIFTH_SENTENCE "4 -> You can press 'c' to change the \
color and go back with 'x'."

# define SIXTH_SENTENCE "5 -> Press 'r' to reset the fractal."

# define SEVENTH_SENTENCE "6 -> Press 'y' while on Julia set so you can change the \
fractal with your mouse."

# define EIGHTH_SENTENCE "Have fun !"

typedef struct s_keys
{
	int	left_arrow;
	int	right_arrow;
	int	up_arrow;
	int	down_arrow;
	int	plus;
	int	minus;
	int	key_c;
	int	key_r;
	int	key_x;
	int	key_y;
}	t_keys;

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	cx;
	double	cy;
	double	r;
	double	i;
	double	j;
	int		color;
	char	*name;
	double	x_julia;
	double	y_julia;
	int		max;
	double	sx;
	double	sy;
	double	zoom;
	double	color_shift;
	int		flag;
	double	first_action;
	t_keys	*keys;
}	t_fractol;

/* calculs.c */
void	calculate_mandelbrot(t_fractol *frac, int x, int y);
void	calculate_julia(t_fractol *frac, int x, int y);
void	calculate_burning(t_fractol *f, int x, int y);
void	draw_fractal(t_fractol *frac);
double	log_calcul(t_fractol *frac);

/* events.c */
int		c_handler(t_fractol *frac);
int		key_starter(int key, t_fractol *frac);
int		key_closer(int key, t_fractol *frac);
int		check_keys(t_fractol *frac);

/* events2.c */
int		zoom(int button, int x, int y, t_fractol *frac);
int		julia_track(int x, int y, t_fractol *f);

/* init.c */
void	init_mlx(t_fractol *frac);
t_keys	*init_keys(void);
void	init_struct(t_fractol *frac, char *str);
void	init_julia(t_fractol *frac, int ac, char **av);

/* utils.c */
void	my_mlx_pixel_put(t_fractol *data, int x, int y, int color);
double	rescale(double num, double nm, double nma, double oma);
int		ft_strcmp(char *s1, char *s2);
double	calcul_strtod(const char *s, int i);
double	ft_strtod(const char *s, char **endptr);

/* utils2.c */
long	get_time(void);
void	print_msg(void);

#endif
