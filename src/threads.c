/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:22:23 by ohamadou          #+#    #+#             */
/*   Updated: 2024/02/10 02:31:54 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void *routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	// printf("starting time: %llu\n", philo->data->start_time);
	// printf("time to eat: %llu\n", philo->time_eat);
	if (philo->philo_number % 2 == 0)
		ft_usleep(philo->time_eat / 2);
	// exit(0);
	while (philo->meals_eaten < philo->data->max_meals_eaten)
	{
		// printf("in l1oop\n");
		is_eating(philo);
		// if (check(philo))
		// 	break;
		is_sleeping(philo);
	
		// if (check(philo))
		// 	break;
		is_thinking(philo);
		// if (check(philo))
		// 	break;
		// print_message(philo, "is thinking");
	}
	return (arg);
}

int create_and_start_threads(t_philo_list *philo_list)
{
	t_philo *current;

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
		{
			break ;
		}
		current = current->next;
	}
	while (current)
	{
		if (pthread_join(current->thread, NULL) != 0)
			return (error_message("Error", current, philo_list));
		if (current == philo_list->first)
		{
			break ;
		}
		current = current->prev;
	}
	// printf("list: %zu\n", philo_list->size);
	return (0);
}
