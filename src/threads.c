/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:22:23 by ohamadou          #+#    #+#             */
/*   Updated: 2024/01/29 06:59:36 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void *routine(void *arg)
{
	t_philo *philo;
	uint64_t start_time;

	// int i = 0;
	start_time = ft_gettime_millisec();
	philo = (t_philo *)arg;
	if (philo->philo_number % 2 != 0)
		usleep(philo->time_eat / 2);
	pthread_mutex_lock(&(philo->fork_right));
	pthread_mutex_lock(&(philo->data->printf));
	printf("philo number: time :%llu took his right fork\n", ft_gettime_millisec() - start_time);
	pthread_mutex_unlock(&(philo->data->printf));
	pthread_mutex_lock(&*(philo->fork_left));
	pthread_mutex_lock(&(philo->data->printf));
	printf("philo number: time :%llu took his left fork\n", ft_gettime_millisec() - start_time);
	pthread_mutex_unlock(&(philo->data->printf));
	pthread_mutex_unlock(&(philo->fork_right));
	pthread_mutex_unlock(&*(philo->fork_left));

	return (arg);
}

int create_and_start_threads(t_philo_list *philo_list)
{
	t_philo *current;

	// int i = 0;
	// printf("am here\n");
	current = philo_list->first;
	while (current)
	{
		if (pthread_create(&(current->thread), NULL, &routine, (void *)current) != 0)
		{
			perror("Failed to cread thread");
			exit(EXIT_FAILURE);
		}
		else
			printf("philo number %d created\n", current->philo_number);
		// i++;
		// if (i == 50)
		// 	break ;
		if (current == philo_list->last)
			break ;
		current = current->next;
	}
	// i = 0;
	// current = philo_list->first;
	while (current)
	{
		if (pthread_join(current->thread, NULL) != 0)
			exit(EXIT_FAILURE);
		if (current == philo_list->first)
			break;
		current = current->prev;
		// i++;
		// if (i == 50)
		// 	break;
		// printf("list size : %zu\n", philo_list->size);
	}
	// pthread_mutex_destroy(&mutex);
	return (0);
}
