/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:26:20 by matle-br          #+#    #+#             */
/*   Updated: 2024/10/31 10:24:21 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_mlx_pixel_put(t_fractol *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

double	rescale(double num, double nm, double nma, double oma)
{
	return ((nma - nm) * (num - 0) / (oma - 0) + nm);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0'))
		i++;
	return (s1[i] - s2[i]);
}

double	calcul_strtod(const char *s, int i)
{
	double	fraction;
	double	diviseur;
	double	valeur;

	fraction = 0.0;
	diviseur = 1.0;
	valeur = 0.0;
	if (s[i] == '.')
	i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		fraction = fraction * 10 + s[i] - '0';
		diviseur *= 10;
		i++;
	}
	valeur += fraction / diviseur;
	return (valeur);
}

double	ft_strtod(const char *s, char **endptr)
{
	int		i;
	double	valeur;
	int		sign;

	i = 0;
	valeur = 0;
	sign = 1;
	while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (s[i] == '+')
		i++;
	while ((s[i] != '.' && s[i] != '\0') && (s[i] >= '0' && s[i] <= '9'))
	{
		valeur = valeur * 10 + s[i] - '0';
		i++;
	}
	valeur += calcul_strtod(s, i);
	if (endptr)
		*endptr = (char *)(s + i);
	return (valeur * sign);
}
