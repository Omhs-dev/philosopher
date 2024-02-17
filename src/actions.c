/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 07:10:14 by ohamadou          #+#    #+#             */
/*   Updated: 2024/02/17 09:35:55 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	is_sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->printf);
	print_message(philo, "is sleeping");
	pthread_mutex_unlock(&philo->data->printf);
	ft_usleep(philo->time_sleep);
}

void	is_thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->printf);
	print_message(philo, "is thinking");
	pthread_mutex_unlock(&philo->data->printf);
}

void	take_the_forks(t_philo *philo)
{
	pthread_mutex_lock(&(philo->fork_right));
	pthread_mutex_lock(&*(philo->fork_left));
	pthread_mutex_lock(&philo->data->printf);
	print_message(philo, "has taken a fork");
	print_message(philo, "has taken a fork");
}

void	drop_the_forks(t_philo *philo)
{
	pthread_mutex_unlock(&(philo->fork_right));
	pthread_mutex_unlock(&*(philo->fork_left));
}

// philo->meals_eaten++;
void	is_eating(t_philo *philo)
{
	take_the_forks(philo);
	print_message(philo, "is eating");
	pthread_mutex_unlock(&philo->data->printf);
	ft_usleep(philo->data->time_eat);
	pthread_mutex_lock(&philo->data->meals_eaten);
	philo->data->max_meals_eaten--;
	pthread_mutex_unlock(&philo->data->meals_eaten);
	pthread_mutex_lock(&philo->data->time);
	philo->start_time = ft_gettime_millisec();
	pthread_mutex_unlock(&philo->data->time);
	drop_the_forks(philo);
}
