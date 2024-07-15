/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:21:06 by matle-br          #+#    #+#             */
/*   Updated: 2024/07/09 16:58:18 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	events_init(t_fractol *frac)
{
	mlx_hook(frac->win, KeyPress, KeyPressMask, key_handler, frac);
	mlx_hook(frac->win, ButtonPress, ButtonPressMask, zoom, frac);
	mlx_hook(frac->win, DestroyNotify, StructureNotifyMask, c_handler, frac);
	mlx_hook(frac->win, MotionNotify, PointerMotionMask, julia_track, frac);
}

int	main(int ac, char **av)
{
	t_fractol	fractol;

	if (ac < 2)
	{
		ft_putendl_fd("Usage: ./fractol <name_of_the_fractol_you_want>", 1);
		ft_putendl_fd("Available fractols: mandelbrot, julia, burning_ship", 1);
		return (0);
	}
	if (ft_strcmp(av[1], "mandelbrot") != 0 && ft_strcmp(av[1], "julia") != 0
		&& ft_strcmp(av[1], "burning_ship") != 0)
	{
		ft_printf("%s\n", "Available: mandelbrot, julia, burning_ship");
		return (0);
	}
	init_mlx(&fractol);
	ft_putendl_fd(WELCOME_MESSAGE, 1);
	init_struct(&fractol, av[1]);
	events_init(&fractol);
	init_julia(&fractol, ac, av);
	draw_fractal(&fractol);
	mlx_loop(fractol.mlx);
	c_handler(&fractol);
	return (0);
}
