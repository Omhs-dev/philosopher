/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 03:10:27 by ohamadou          #+#    #+#             */
/*   Updated: 2024/02/10 02:29:02 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int check(t_philo *philo)
{
	if (philo->meals_eaten == philo->data->max_meals_eaten)
		return (1);
	return (0);
}

void is_sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->printf);
	print_message(philo, "is sleeping");
	pthread_mutex_unlock(&philo->data->printf);
	ft_usleep(philo->time_sleep);
}

void is_thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->printf);
	print_message(philo, "is thinking");
	pthread_mutex_unlock(&philo->data->printf);
}

void print_message(t_philo *philo, char *str)
{
	uint64_t curren_time;

	curren_time = ft_gettime_millisec() - philo->data->start_time;
	// pthread_mutex_lock(&philo->data->printf);
	printf("%llu %d %s\n", curren_time, philo->philo_number, str);
	// pthread_mutex_unlock(&philo->data->printf);
}

void take_the_forks(t_philo *philo)
{
		pthread_mutex_lock(&(philo->fork_right));
		// printf("before taking the fork\n");
		pthread_mutex_lock(&*(philo->fork_left));
		pthread_mutex_lock(&philo->data->printf);
		print_message(philo, "has taken a fork");
		// printf("before taking the fork\n");
		print_message(philo, "has taken a fork");
		// printf("after taking the fork\n");
}

void drop_the_forks(t_philo *philo)
{
		pthread_mutex_unlock(&(philo->fork_right));
		pthread_mutex_unlock(&*(philo->fork_left));
}

void is_eating(t_philo *philo)
{
	take_the_forks(philo);
	print_message(philo, "is eating");
	pthread_mutex_unlock(&philo->data->printf);
	ft_usleep(philo->data->time_eat);
	philo->meals_eaten++;
	drop_the_forks(philo);
}
