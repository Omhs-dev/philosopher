/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:28:50 by ohamadou          #+#    #+#             */
/*   Updated: 2024/02/14 05:23:55 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int ft_atoi(char *str)
{
	int sign;
	int opr;

	sign = 1;
	opr = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
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

void add_to_list(t_philo_list **list, t_philo **philo)
{
	if ((*list)->first == NULL)
	{
		(*list)->first = (*philo);
		(*list)->last = (*philo);
		(*philo)->next = NULL;
		(*philo)->prev = NULL;
		(*list)->size++;
	}
	else
	{
		(*list)->last->next = (*philo);
		(*philo)->prev = (*list)->last;
		(*list)->last = (*philo);
		(*philo)->next = (*list)->first;
		(*list)->first->prev = (*philo);
		(*list)->size++;
	}
}

#include <stdio.h>

t_philo_list *creat_list(char **argv, t_data **data)
{
	int i;
	t_philo_list *list;
	t_philo *phil;
	t_philo *current;

	i = 0;
	list = init_list();
	while (i < ft_atoi(argv[1]))
	{
		phil = init_philo(argv, &(*data));
		phil->philo_number = i + 1;
		add_to_list(&list, &phil);
		i++;
	}
	current = list->first;
	while (current != list->last)
	{
		current->fork_left = &(current->prev->fork_right);
		current = current->next;
	}
	current->fork_left = &(current->prev->fork_right);
	return (list);
}

void ft_free(t_philo_list *list)
{
	free(list->first);
	free(list);
}

void destroy_mutex(t_philo_list *list)
{
	// pthread_mutex_destroy(&*(current->fork_left));
	pthread_mutex_destroy(&(list->first->fork_right));
	pthread_mutex_destroy(&(list->first->data->printf));
	pthread_mutex_destroy(&(list->first->data->check_death));
	// ft_free(list);
}

int error_message(char *str, t_philo_list *list)
{
	printf("%s\n", str);
	destroy_mutex(list);
	ft_free(list);
	return (1);
}

void ft_usleep(uint64_t millsec)
{
	uint64_t time;

	time = ft_gettime_millisec() + millsec;
	while (ft_gettime_millisec() != time)
		usleep(500);
}

void error_return(void)
{
	printf("Error: invalid input\n");
	return ;
}


