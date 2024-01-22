/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:45:52 by ohamadou          #+#    #+#             */
/*   Updated: 2024/01/22 20:40:28 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int ft_atoi(char *str)
{
	int sign;
	int opr;

	sign = 1;
	opr = 0;
	while (*str == ' ' && (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		opr = opr * 10 + *str - '0';
		str++;
	}
	return (sign * opr);
}

t_philo *init_philo(char **argv)
{
	t_philo *phil;
	
	
	(void)argv;
	phil = malloc(sizeof(t_philo));
	if (!phil)
		return (NULL);
	pthread_mutex_init(&(phil->fork_right), NULL);
	// phil->time_die = argv[2];
	// phil->time_eat = argv[3];
	// phil->time_sleep = argv[4];
	phil->next = NULL;
	phil->prev = NULL;
	// phil->time_sleep = 0;
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
