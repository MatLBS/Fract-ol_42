/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:47:24 by matle-br          #+#    #+#             */
/*   Updated: 2024/07/09 16:58:08 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <math.h>
# include <pthread.h>
# include <X11/X.h>
# include <X11/keysym.h>

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

# define WELCOME_MESSAGE "Welcome, this is a manual on how you can modify \
this project with the keyboard!\n\n \
1 -> First, you can use the four arrows to move.\n\n \
2 -> Then, you can use the mouse wheel to zoom / dezoom.\n\n \
3 -> You can press the buttons '+' / '-' to increase / decrease  \
the precision.\n\n \
4 -> You can press 'c' to change the color and go back with 'x'.\n\n \
5 -> Press 'r' to reset the fractal.\n\n \
6 -> Press 'y' while on Julia set so you can change the \
fractal with your mouse\n\n \
Have fun !\n"

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
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
}	t_fractol;

void	init_mlx(t_fractol *frac);
void	draw_fractal(t_fractol *frac);
void	calculate_mandelbrot(t_fractol *fractol, int x, int y);
void	my_mlx_pixel_put(t_fractol *data, int x, int y, int color);
void	ft_putendl_fd(char *s, int fd);
double	rescale(double num, double nm, double nma, double oma);
int		ft_strcmp(char *s1, char *s2);
void	init_struct(t_fractol *frac, char *str);
void	my_mlx_pixel_put(t_fractol *data, int x, int y, int color);
void	calculate_julia(t_fractol *fractol, int x, int y);
double	calcul_strtod(const char *s, int i);
double	ft_strtod(const char *s, char **endptr);
int		c_handler(t_fractol *frac);
int		key_handler(int key, t_fractol *frac);
void	events_init(t_fractol *frac);
int		zoom(int button, int x, int y, t_fractol *frac);
double	log_calcul(t_fractol *frac);
int		handle_mouse(int button, int x, int y, t_fractol *frac);
void	init_julia(t_fractol *frac, int ac, char **av);
int		julia_track(int x, int y, t_fractol *f);

#endif
