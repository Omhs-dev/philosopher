/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:28:50 by ohamadou          #+#    #+#             */
/*   Updated: 2024/02/12 09:04:09 by ohamadou         ###   ########.fr       */
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

void ft_free(t_philo *philo, t_data *data, t_philo_list *list)
{
	free(data);
	free(philo);
	free(list);
}

void destroy_mutex(t_philo *philo, t_philo_list *list)
{
	philo = list->first;
	while (philo)
	{
		pthread_mutex_destroy(&*(philo->fork_left));
		pthread_mutex_destroy(&(philo->fork_right));
		philo = philo->next;
	}
	pthread_mutex_destroy(&(philo->data->printf));
	ft_free(philo, philo->data, list);
}

int error_message(char *str, t_philo *philo, t_philo_list *list)
{
	printf("%s\n", str);
	if (list)
		destroy_mutex(philo, list);
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

void cleanup(t_philo_list *philo_list, t_data *data)
{
    // Destroy mutexes
    t_philo *current = philo_list->first;
    while (current) {
        pthread_mutex_destroy(&current->fork_right);
        current = current->next;
    }

    // Free dynamically allocated memory for philosophers
    current = philo_list->first;
    while (current) {
        t_philo *next = current->next;
        free(current); // Assuming t_philo struct itself was dynamically allocated
        current = next;
    }
    free(philo_list); // Assuming philo_list itself was dynamically allocated

    // Free dynamically allocated memory for data
    free(data); // Assuming t_data struct itself was dynamically allocated

    // Print message
    printf("Cleanup completed successfully\n");
}

