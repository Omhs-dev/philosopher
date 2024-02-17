/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 03:10:27 by ohamadou          #+#    #+#             */
/*   Updated: 2024/02/17 09:33:40 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_message(t_philo *philo, char *str)
{
	uint64_t	curren_time;

	curren_time = ft_gettime_millisec() - philo->data->start_time;
	if (check(philo))
		return ;
	printf("%llu %d %s\n", curren_time, philo->philo_number, str);
}

void	one_philo(t_philo *philo)
{
	uint64_t	time;

	if (philo->data->numbers_of_philo == 1)
	{
		pthread_mutex_lock(&philo->fork_right);
		time = ft_gettime_millisec();
		printf("%llu %d has taken a fork\n",
			time - philo->data->start_time, philo->philo_number);
	}
}

void	philo_that_think(t_philo *philo)
{
	if ((philo->philo_number % 2 == 0
			|| (philo->philo_number == philo->data->numbers_of_philo
				&& philo->philo_number % 2 == 1))
		&& (philo->data->numbers_of_philo != 1))
	{
		is_thinking(philo);
		ft_usleep(1);
	}
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo_that_think(philo);
	while (check_meals_eaten(philo) != 0
		&& check_death_status(philo) == 0
		&& (philo->data->numbers_of_philo != 1))
	{
		if (check(philo) == 1)
			return (NULL);
		is_eating(philo);
		if (check(philo) == 1)
			return (NULL);
		is_sleeping(philo);
		if (check(philo) == 1)
			return (NULL);
		is_thinking(philo);
		if (check(philo) == 1)
			return (NULL);
	}
	one_philo(philo);
	return (arg);
}
