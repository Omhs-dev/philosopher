/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:22:23 by ohamadou          #+#    #+#             */
/*   Updated: 2024/02/12 07:48:25 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void *routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	// printf("starting time: %llu\n", philo->data->start_time);
	// printf("time to eat: %llu\n", philo->time_eat);
	if (philo->philo_number % 2 == 0 ||
		(philo->philo_number == philo->data->numbers_of_philo && philo->philo_number % 2 == 1))
	{
		is_thinking(philo);
		ft_usleep(1);
	}
	// exit(0);
	while (philo->meals_eaten != philo->data->max_meals_eaten && philo->data->death_status == 0)
	{
		// printf("in l1oop\n");
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
		// philo->data->start_time = ft_gettime_millisec();
	}
	return (arg);
}

int create_and_start_threads(t_philo_list *philo_list)
{
	t_philo *current;
	uint64_t current_time;
	current = philo_list->first;
	// if (current->data->meal_eaten > 0)
	// {
	// 	if (pthread_create(&(current->thread), NULL, &monitoring, (void *)current) != 0)
	// 		return (error_message("Error", current, philo_list));
	// }
	while (current)
	{
		if (pthread_create(&(current->thread), NULL, &routine, (void *)current) != 0)
			return (error_message("Error", current, philo_list));
		// else
		// 	printf("philo number %d created\n", current->philo_number);
		if (current == philo_list->last)
			break ;
		current = current->next;
	}
	while (current)
	{
		current_time = ft_gettime_millisec() - current->start_time;
		pthread_mutex_lock(&current->data->check_death);
		if (current_time > current->time_die)
		{
			current->data->death_status = 1;
			pthread_mutex_lock(&current->data->printf);
			printf("%llu %d %s\n", current_time, current->philo_number, "dies");
			pthread_mutex_unlock(&current->data->printf);
			pthread_mutex_unlock(&current->data->check_death);
			printf("here hey\n");
			return (1);
		}
		pthread_mutex_unlock(&current->data->check_death);
		current = current->next;
	}
	while (current)
	{
		if (pthread_join(current->thread, NULL) != 0)
			return (error_message("Error", current, philo_list));
		if (current == philo_list->first)
			break ;
		current = current->prev;
	}
	return (0);
}
