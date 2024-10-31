/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:15:22 by matle-br          #+#    #+#             */
/*   Updated: 2024/10/31 16:53:44 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	zoom(int key, int x, int y, t_fractol *frac)
{
	(void)x;
	(void)y;
	if (key == Button4)
	frac->zoom *= 0.95;
	if (key == Button5)
		frac->zoom *= 1.05;
	return (0);
}

int	julia_track(int x, int y, t_fractol *f)
{
	if (ft_strcmp(f->name, "julia") == 0 && f->flag == 1)
	{
		f->x_julia = (rescale(x, X_MIN, X_MAX, f->width) * f->zoom) + f->sx;
		f->y_julia = (rescale(y, Y_MAX, Y_MIN, f->height) * f->zoom) + f->sy;
		draw_fractal(f);
	}
	return (0);
}
