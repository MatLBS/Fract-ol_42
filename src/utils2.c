/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:24:12 by matle-br          #+#    #+#             */
/*   Updated: 2024/10/31 10:49:01 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

long	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
	{
		printf("Error with gettimeofday");
		return (-1);
	}
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	print_msg(void)
{
	ft_putendl_fd(FIRST_SENTENCE, 1);
	ft_putendl_fd(SECOND_SENTENCE, 1);
	ft_putendl_fd(THIRD_SENTENCE, 1);
	ft_putendl_fd(FOURTH_SENTENCE, 1);
	ft_putendl_fd(FIFTH_SENTENCE, 1);
	ft_putendl_fd(SIXTH_SENTENCE, 1);
	ft_putendl_fd(SEVENTH_SENTENCE, 1);
	ft_putendl_fd(EIGHTH_SENTENCE, 1);
}
