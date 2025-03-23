/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:53:17 by amysiv            #+#    #+#             */
/*   Updated: 2025/03/23 20:23:37 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_action(char *s, t_philo *philo)
{
	pthread_mutex_lock(&philo->program->status_mutex);
	if (philo->program->status == true)
	{
		printf("%ld %d %s\n", (get_time() - philo->program->start_time), \
		philo->index, s);
		pthread_mutex_unlock(&philo->program->status_mutex);
		return ;
	}
	pthread_mutex_unlock(&philo->program->status_mutex);
}
