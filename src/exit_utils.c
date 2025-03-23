/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 13:43:43 by amysiv            #+#    #+#             */
/*   Updated: 2025/03/23 20:23:22 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	join(int counter, t_program *data)
{
	int	i;

	i = 0;
	while (counter > i)
	{
		if (pthread_join(data->philos[i].thread, NULL) == -1)
		{
			free(data->philos);
			return (-1);
		}
		i++;
	}
	return (1);
}

int	destroy_fork_mutex(t_program *data, int fork_count)
{
	int	i;

	i = 0;
	while (i < fork_count)
	{
		if (pthread_mutex_destroy(&data->philos[i].r_fork) == -1)
		{
			free(data->philos);
			return (-1);
		}
		i++;
	}
	return (1);
}

int	destroy_extra_mutex(t_program *data)
{
	if (pthread_mutex_destroy(&data->print_mutex) == -1)
	{
		free(data->philos);
		return (-1);
	}
	if (pthread_mutex_destroy(&data->status_mutex) == -1)
	{
		free(data->philos);
		return (-1);
	}
	if (pthread_mutex_destroy(&data->meal_mutex) == -1)
	{
		free(data->philos);
		return (-1);
	}
	return (1);
}
