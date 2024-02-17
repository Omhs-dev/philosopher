/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 07:15:56 by ohamadou          #+#    #+#             */
/*   Updated: 2024/02/17 09:33:16 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	add_to_list(t_philo_list **list, t_philo **philo)
{
	if ((*list)->first == NULL)
	{
		(*list)->first = (*philo);
		(*list)->last = (*philo);
		(*philo)->next = (*list)->last;
		(*philo)->prev = (*list)->first;
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

t_philo_list	*creat_list(char **argv, t_data **data)
{
	int				i;
	t_philo_list	*list;
	t_philo			*phil;
	t_philo			*current;

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
