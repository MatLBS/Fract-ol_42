/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:56:44 by matle-br          #+#    #+#             */
/*   Updated: 2024/10/31 16:53:14 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	c_handler(t_fractol *frac)
{
	mlx_destroy_image(frac->mlx, frac->img);
	mlx_destroy_window(frac->mlx, frac->win);
	mlx_destroy_display(frac->mlx);
	free(frac->mlx);
	if (frac->keys)
		free(frac->keys);
	exit(EXIT_FAILURE);
	return (0);
}

int	key_starter(int key, t_fractol *frac)
{
	if (key == XK_Escape)
		c_handler(frac);
	if (key == XK_Left)
		frac->keys->left_arrow = 1;
	if (key == XK_Right)
		frac->keys->right_arrow = 1;
	if (key == XK_Up)
		frac->keys->up_arrow = 1;
	if (key == XK_Down)
		frac->keys->down_arrow = 1;
	if (key == XK_PLUS)
		frac->keys->plus = 1;
	if (key == XK_MIN)
		frac->keys->minus = 1;
	if (key == XK_c)
		frac->keys->key_c = 1;
	if (key == XK_x)
		frac->keys->key_x = 1;
	if (key == XK_r)
		frac->keys->key_r = 1;
	if (key == XK_y)
		frac->keys->key_y = 1;
	return (0);
}

int	key_closer(int key, t_fractol *frac)
{
	if (key == XK_Left)
		frac->keys->left_arrow = 0;
	if (key == XK_Right)
		frac->keys->right_arrow = 0;
	if (key == XK_Up)
		frac->keys->up_arrow = 0;
	if (key == XK_Down)
		frac->keys->down_arrow = 0;
	if (key == XK_PLUS)
		frac->keys->plus = 0;
	if (key == XK_MIN)
		frac->keys->minus = 0;
	if (key == XK_c)
		frac->keys->key_c = 0;
	if (key == XK_x)
		frac->keys->key_x = 0;
	if (key == XK_r)
		frac->keys->key_r = 0;
	if (key == XK_y)
		frac->keys->key_y = 0;
	return (0);
}

int	check_keys(t_fractol *frac)
{
	if (frac->keys->left_arrow == 1)
		frac->sx -= (0.5 * frac->zoom);
	if (frac->keys->right_arrow == 1)
		frac->sx += (0.5 * frac->zoom);
	if (frac->keys->up_arrow == 1)
		frac->sy += (0.5 * frac->zoom);
	if (frac->keys->down_arrow == 1)
		frac->sy -= (0.5 * frac->zoom);
	if (frac->keys->plus == 1)
		frac->max += 10;
	if (frac->keys->minus == 1)
		frac->max -= 10;
	if (frac->keys->key_c == 1)
		frac->color_shift *= 2;
	if (frac->keys->key_x == 1)
		frac->color_shift /= 2;
	if (frac->keys->key_r == 1)
		init_struct(frac, frac->name);
	if (frac->keys->key_y == 1)
		frac->flag *= -1;
	draw_fractal(frac);
	return (0);
}
