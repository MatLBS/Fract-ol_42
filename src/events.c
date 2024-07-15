/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:56:44 by matle-br          #+#    #+#             */
/*   Updated: 2024/07/15 12:07:43 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	c_handler(t_fractol *frac)
{
	mlx_destroy_image(frac->mlx, frac->img);
	mlx_destroy_window(frac->mlx, frac->win);
	mlx_destroy_display(frac->mlx);
	free(frac->mlx);
	exit(EXIT_FAILURE);
	return (0);
}

int	key_handler(int key, t_fractol *frac)
{
	if (key == XK_Escape)
		c_handler(frac);
	else if (key == XK_Left)
		frac->sx -= (0.5 * frac->zoom);
	else if (key == XK_Right)
		frac->sx += (0.5 * frac->zoom);
	else if (key == XK_Up)
		frac->sy += (0.5 * frac->zoom);
	else if (key == XK_Down)
		frac->sy -= (0.5 * frac->zoom);
	else if (key == XK_PLUS)
		frac->max += 10;
	else if (key == XK_MIN)
		frac->max -= 10;
	else if (key == XK_c)
		frac->color_shift *= 2;
	else if (key == XK_x)
		frac->color_shift /= 2;
	else if (key == XK_r)
		init_struct(frac, frac->name);
	else if (key == XK_y)
		frac->flag *= -1;
	draw_fractal(frac);
	return (0);
}

int	zoom(int button, int x, int y, t_fractol *frac)
{
	(void)x;
	(void)y;
	if (button == Button4)
		frac->zoom *= 0.95;
	else if (button == Button5)
		frac->zoom *= 1.05;
	draw_fractal(frac);
	return (0);
}

int	julia_track(int x, int y, t_fractol *f)
{
	if (ft_strcmp(f->name, "julia") == 0 && f->flag == 1)
	{
		f->x_julia = (rescale(x, X_MIN, X_MAX, WIDTH) * f->zoom) + f->sx;
		f->y_julia = (rescale(y, Y_MAX, Y_MIN, HEIGHT) * f->zoom) + f->sy;
		draw_fractal(f);
	}
	return (0);
}
