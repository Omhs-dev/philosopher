/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:45:52 by ohamadou          #+#    #+#             */
/*   Updated: 2024/01/29 06:56:27 by ohamadou         ###   ########.fr       */
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
	phil->data = *data;
	phil->philo_number = 0;
	phil->time_sleep = (*data)->time_sleep;
	phil->time_eat = (*data)->time_eat;
	phil->time_die = (*data)->time_die;
	// phil->time_think = (*data)->time_think;
	// phil->time_eat = argv[3];
	// phil->time_sleep = argv[4];
	phil->next = NULL;
	phil->prev = NULL;
	// phil->fork = 
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

t_data *init_data(char **argv)
{
	t_data *data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->time_die = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	pthread_mutex_init(&(data->printf), NULL);
	return (data);
}
