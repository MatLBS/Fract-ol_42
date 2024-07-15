/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:36:16 by matle-br          #+#    #+#             */
/*   Updated: 2024/07/03 13:43:43 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	calculate_mandelbrot(t_fractol *frac, int x, int y)
{
	double	tmp_r;
	double	j;

	j = 0;
	frac->i = 0.0;
	frac->r = 0.0;
	frac->cx = (rescale(x, X_MIN, X_MAX, WIDTH) * frac->zoom) + frac->sx;
	frac->cy = (rescale(y, Y_MAX, Y_MIN, HEIGHT) * frac->zoom) + frac->sy;
	while (frac->r * frac->r - frac->i * frac->i <= (1 << 16) && j < frac->max)
	{
		tmp_r = frac->r * frac->r - frac->i * frac->i + frac->cx;
		frac->i = 2 * frac->r * frac->i + frac->cy;
		frac->r = tmp_r;
		j++;
	}
	if (j < frac->max)
	{
		j = j + 1 - log_calcul(frac);
		if (frac->color_shift > 2139095000)
			frac->color_shift = 255;
		frac->color = rescale(j, 0, frac->color_shift, frac->max);
		my_mlx_pixel_put(frac, x, y, frac->color);
	}
	else
		my_mlx_pixel_put(frac, x, y, 0x000000);
}

void	calculate_julia(t_fractol *frac, int x, int y)
{
	double	tmp_r;
	double	tmp_i;
	int		j;

	j = 0;
	frac->r = (rescale(x, X1_MIN, X1_MAX, HEIGHT) * frac->zoom) + frac->sx;
	frac->i = (rescale(y, Y1_MAX, Y1_MIN, WIDTH) * frac->zoom) + frac->sy;
	while (j < frac->max)
	{
		tmp_r = frac->r * frac->r - frac->i * frac->i + frac->x_julia;
		tmp_i = (2 * frac->r * frac->i) + frac->y_julia;
		frac->r = tmp_r;
		frac->i = tmp_i;
		if (frac->r * frac->r + frac-> i * frac->i >= 4.0)
		{
			if (frac->color_shift > 2139095000)
				frac->color_shift = 255;
			frac->color = rescale(j, 0, frac->color_shift, frac->max);
			my_mlx_pixel_put(frac, x, y, frac->color);
			return ;
		}
		j++;
	}
	my_mlx_pixel_put(frac, x, y, 0x000000);
}

void	calculate_burning(t_fractol *f, int x, int y)
{
	double	tmp_r;

	f->j = -1;
	f->i = 0.0;
	f->r = 0.0;
	f->cx = (rescale(x, X_MIN, X_MAX, WIDTH) * f->zoom) + f->sx;
	f->cy = (rescale(y, Y_MIN, Y_MAX, HEIGHT) * f->zoom) - f->sy;
	while (f->r * f->r - f->i * f->i <= (1 << 16) && ++f->j < f->max)
	{
		f->i = fabs(f->i);
		f->r = fabs(f->r);
		tmp_r = f->r * f->r - f->i * f->i + f->cx;
		f->i = 2 * f->r * f->i + f->cy;
		f->r = tmp_r;
	}
	if (f->j < f->max)
	{
		f->j = f->j + 1 - log_calcul(f);
		if (f->color_shift > 2139095000)
			f->color_shift = 255;
		f->color = rescale(f->j, 0, f->color_shift, f->max);
		my_mlx_pixel_put(f, x, y, f->color);
	}
	else
		my_mlx_pixel_put(f, x, y, 0x000000);
}

void	draw_fractal(t_fractol *frac)
{
	int		y;
	int		x;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (ft_strcmp(frac->name, "mandelbrot") == 0)
				calculate_mandelbrot(frac, x, y);
			else if (ft_strcmp(frac->name, "julia") == 0)
				calculate_julia(frac, x, y);
			else if (ft_strcmp(frac->name, "burning_ship") == 0)
				calculate_burning(frac, x, y);
			else
				ft_putendl_fd("Available : mandelbrot, julia, burning_ship", 1);
		}
	}
	mlx_put_image_to_window(frac->mlx, frac->win, frac->img, 0, 0);
}

double	log_calcul(t_fractol *frac)
{
	double	log_zn;
	double	nu;

	log_zn = log(frac->r * frac->r + frac->i * frac->i) / 2.0;
	nu = log(log_zn / log(2)) / log(2);
	return (nu);
}
