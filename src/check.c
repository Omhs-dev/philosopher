/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 07:07:45 by ohamadou          #+#    #+#             */
/*   Updated: 2024/02/17 09:32:57 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_death_status(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->check_death);
	if (philo->data->death_status == 0)
	{
		pthread_mutex_unlock(&philo->data->check_death);
		return (0);
	}
	else
	{
		pthread_mutex_unlock(&philo->data->check_death);
		return (1);
	}
}

int	check_meals_eaten(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->meals_eaten);
	if (philo->data->max_meals_eaten == 0)
	{
		pthread_mutex_unlock(&philo->data->meals_eaten);
		return (0);
	}
	else
	{
		pthread_mutex_unlock(&philo->data->meals_eaten);
		return (1);
	}
}

int	check_maxmeals_eaten(t_philo *philo)
{
	int	meals_eaten;

	pthread_mutex_lock(&philo->data->meals_eaten);
	meals_eaten = philo->meals_eaten;
	pthread_mutex_unlock(&philo->data->meals_eaten);
	pthread_mutex_lock(&philo->data->meals_eaten);
	if (meals_eaten == philo->data->max_meals_eaten)
	{
		pthread_mutex_unlock(&philo->data->meals_eaten);
		return (0);
	}
	else
	{
		pthread_mutex_unlock(&philo->data->meals_eaten);
		return (1);
	}
}

void	check_philo_death(t_philo *philo, uint64_t current_time)
{
	if (philo->data->death_status == 0)
	{
		philo->data->death_status = 1;
		pthread_mutex_lock(&philo->data->printf);
		if (check_maxmeals_eaten(philo) == 0)
		{
			pthread_mutex_unlock(&philo->data->printf);
			pthread_mutex_unlock(&philo->data->check_death);
			return ;
		}
		printf("%llu %d %s\n", current_time, philo->philo_number, "died");
		pthread_mutex_unlock(&philo->data->printf);
	}
}

int	check(t_philo *philo)
{
	uint64_t	time;
	uint64_t	current_time;

	pthread_mutex_lock(&philo->data->time);
	time = ft_gettime_millisec() - philo->start_time;
	pthread_mutex_unlock(&philo->data->time);
	current_time = ft_gettime_millisec() - philo->data->start_time;
	pthread_mutex_lock(&philo->data->check_death);
	if (check_meals_eaten(philo) == 0 && philo->data->death_status == 0)
	{
		philo->data->death_status = 1;
		pthread_mutex_unlock(&philo->data->check_death);
		return (1);
	}
	if (time > philo->data->time_die)
		check_philo_death(philo, current_time);
	if (philo->data->death_status == 1)
	{
		pthread_mutex_unlock(&philo->data->check_death);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->check_death);
	return (0);
}
