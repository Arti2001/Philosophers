/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amysiv <amysiv@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:48:41 by amysiv            #+#    #+#             */
/*   Updated: 2024/08/02 00:09:52 by amysiv           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo	t_philo;

typedef struct s_program
{
	long					p_numb;
	long					die_time;
	long					eat_time;
	long					sleep_time;
	long					eat_numb;
	long					start_time;
	bool					status;
	pthread_mutex_t			status_mutex;
	pthread_mutex_t			meal_mutex;
	pthread_mutex_t			print_mutex;
	t_philo					*philos;
}	t_program;

typedef struct s_philo
{
	int						index;
	long					last_meal;
	bool					is_full;
	int						meal_count;
	t_program				*program;
	pthread_t				thread;
	pthread_mutex_t			*l_fork;
	pthread_mutex_t			r_fork;
}	t_philo;

long	ft_atol(const char *nbr);
void	atol_arguments(t_program *arg_data, char **argv, int argc);
int		destroy_fork_mutex(t_program *data, int counter);
int		destroy_extra_mutex(t_program *data);
int		check_numb(char **numb);

int		start_simulation(t_program *data);
void	*routine(void *arg);
void	my_usleep(int time, t_program *data);
long	get_time(void);

void	init_philo(t_program *data);
int		thread_init(t_philo *philo, int thread_count, int fork_count);
int		fork_init(t_philo *philo, int fork_count);
int		init_extra_mutex(t_program *data);
int		philo_fork_init(t_program *data);
void	monitor(t_program *data);
int		meal_check(t_program *data);
int		join(int countre, t_program *data);

void	print_action(char *str, t_philo *philo);
bool	is_died(t_philo *philo);

#endif