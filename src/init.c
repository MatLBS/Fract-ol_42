/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:57:06 by matle-br          #+#    #+#             */
/*   Updated: 2024/06/24 10:44:32 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_mlx(t_fractol *frac)
{
	frac->mlx = mlx_init();
	if (!frac->mlx)
		exit(EXIT_FAILURE);
	frac->win = mlx_new_window(frac->mlx, WIDTH, HEIGHT, "fract'ol");
	if (!frac->win)
	{
		mlx_destroy_display(frac->mlx);
		free(frac->mlx);
		exit(EXIT_FAILURE);
	}
	frac->img = mlx_new_image(frac->mlx, WIDTH, HEIGHT);
	if (!frac->img)
		c_handler(frac);
	frac->addr = mlx_get_data_addr(frac->img,
			&frac->bits_per_pixel,
			&frac->line_length,
			&frac->endian);
	if (!frac->addr)
	{
		mlx_destroy_image(frac->mlx, frac->img);
		mlx_destroy_window(frac->mlx, frac->win);
		mlx_destroy_display(frac->mlx);
		free(frac->mlx);
		exit(EXIT_FAILURE);
	}
}

void	init_struct(t_fractol *frac, char *str)
{
	frac->cx = 0.0;
	frac->cy = 0.0;
	frac->r = 0.0;
	frac->i = 0.0;
	frac->color = 0xFFFFFF;
	frac->color_shift = 255;
	frac->name = str;
	frac->x_julia = -1.0;
	frac->y_julia = 0.0;
	frac->max = 60;
	frac->sx = 0.0;
	frac->sy = 0.0;
	frac->zoom = 1.0;
	frac->j = 0.0;
	frac->flag = -1;
}

void	init_julia(t_fractol *frac, int ac, char **av)
{
	char	*tod;
	char	*tod1;

	if (ft_strcmp(av[1], "julia") == 0 && ac == 3)
		frac->x_julia = ft_strtod(av[2], &tod);
	if (ft_strcmp(av[1], "julia") == 0 && ac == 4)
	{
		frac->x_julia = ft_strtod(av[2], &tod);
		frac->y_julia = ft_strtod(av[3], &tod1);
	}
}
