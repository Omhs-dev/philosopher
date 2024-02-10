/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:45:52 by ohamadou          #+#    #+#             */
/*   Updated: 2024/02/10 01:45:22 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_philo *init_philo(char **argv, t_data **data)
{
	t_philo *phil;
	
	(void)argv;
	phil = malloc(sizeof(t_philo));
	if (!phil)
		return (NULL);
	pthread_mutex_init(&(phil->fork_right), NULL);
	pthread_mutex_init(&(phil->handle_mutex), NULL);
	phil->meals_eaten = 0;
	phil->data = *data;
	// phil->eat_status = 0;
	phil->philo_number = 0;
	phil->time_sleep = (*data)->time_sleep;
	phil->time_eat = (*data)->time_eat;
	phil->time_die = (*data)->time_die;
	phil->next = NULL;
	phil->prev = NULL;
	return (phil);
}

t_philo_list *init_list(void)
{
	t_philo_list *list;

	list = malloc(sizeof(t_philo_list));
	if (!list)
		return (NULL);
	list->first = NULL;
	list->last = NULL;
	list->size = 0;
	return (list);
}

t_data *init_data(int argc, char **argv)
{
	t_data *data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->done = 0;
	data->start_time = ft_gettime_millisec();
	data->death_status = 0;
	data->time_die = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->max_meals_eaten  = ft_atoi(argv[5]);
	else
		data->max_meals_eaten = -1;
	pthread_mutex_init(&(data->printf), NULL);
	// pthread_mutex_init(&(data->handle_mutex), NULL);
	return (data);
}
