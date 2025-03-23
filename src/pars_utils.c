/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:22:35 by amysiv            #+#    #+#             */
/*   Updated: 2025/03/23 20:23:34 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	ft_atol(const char *nbr)
{
	long	result;
	int		i;

	result = 0;
	i = 0;
	while (nbr[i] == 32 || (nbr[i] >= 9 && nbr[i] <= 13))
		i++;
	if (nbr[i] == '+')
		i++;
	while (nbr[i] >= '0' && nbr[i] <= '9')
	{
		result = result * 10 + nbr[i] - 48;
		i++;
	}
	return (result);
}

int	check_numb(char **numb)
{
	int	i;
	int	l;

	i = 1;
	while (numb[i])
	{
		l = 0;
		if (numb[i][l] == '-' || numb[i][l] == '0' || numb[i][l] == '\0')
			return (0);
		if (numb[i][l] == '+')
			l++;
		while (numb[i][l])
		{
			if (numb[i][l] >= '0' && numb[i][l] <= '9')
				l++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

void	atol_arguments(t_program *arg_data, char **argv, int argc)
{
	arg_data->p_numb = ft_atol(argv[1]);
	arg_data->die_time = ft_atol(argv[2]);
	arg_data->eat_time = ft_atol(argv[3]);
	arg_data->sleep_time = ft_atol(argv[4]);
	arg_data->eat_numb = 0;
	if (argc == 6)
		arg_data->eat_numb = ft_atol(argv[5]);
}

long	get_time(void)
{
	struct timeval	p;

	if (gettimeofday(&p, NULL) == -1)
		return (-1);
	return (p.tv_sec * 1000 + p.tv_usec / 1000);
}

void	my_usleep(int ms, t_program *data)
{
	long	wake_up;

	wake_up = ms + get_time();
	while (wake_up > get_time())
	{
		usleep(100);
		if (data->p_numb > 1)
		{
			pthread_mutex_lock(&data->status_mutex);
			if (data->status == false)
			{
				pthread_mutex_unlock(&data->status_mutex);
				return ;
			}
			pthread_mutex_unlock(&data->status_mutex);
		}
	}
}
