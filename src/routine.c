/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 03:10:27 by ohamadou          #+#    #+#             */
/*   Updated: 2024/01/29 04:52:46 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// void *start_routine(void *ptr)
// {
// 	t_philo *philo = (t_philo *)ptr;
// 	uint64_t start_time;

// 	philo->id = 0;
// 	start_time = ft_gettime_millisec();
// 	printf("starting time %llu\n", 	start_time);
// 	while (1)
// 	{
// 		pthread_mutex_lock(&(philo->fork_right));
// 		printf("philo number %d: time :%llu took his right fork\n", philo->id, ft_gettime_millisec() - start_time);
// 		pthread_mutex_lock(&*(philo->fork_left));
// 		printf("philo number %d: time :%llu took his left fork\n", philo->id, ft_gettime_millisec() - start_time);
// 		pthread_mutex_unlock(&(philo->fork_right));
// 		pthread_mutex_unlock(&*(philo->fork_left));

// 		// Philosopher is sleeping
// 		printf("Philosopher %d is sleeping\n", philo->id);
// 		usleep(1000); // Sleep for 1 millisecond (adjust as needed)

// 		// Philosopher is thinking
// 		printf("Philosopher %d is thinking\n", philo->id);
// 		philo->id++;
// 		if (philo->id == 10)
// 			break ;
// 	}
// 	return NULL;
// }

// void eat(t_philo *philo)
// {
// 	printf("philo %d is eating", philo->id);
// }

// int main()
// {
// 	pthread_t t_id;

// 	printf("before threads\n");
// 	pthread_create(&t_id, NULL, routine, NULL);
// 	pthread_join(t_id, NULL);
// 	printf("after thread\n");
// 	exit(0);
// }