/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:22:23 by ohamadou          #+#    #+#             */
/*   Updated: 2024/02/17 09:17:50 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	join_threads(t_philo *philo, t_philo_list *list)
{
	while (philo)
	{
		if (pthread_join(philo->thread, NULL) != 0)
			error_message("Error", list);
		if (philo == list->first)
			break ;
		philo = philo->prev;
	}
}

int	create_and_start_threads(t_philo_list *philo_list)
{
	t_philo	*current;
	t_philo	*current2;

	current = philo_list->first;
	while (current)
	{
		if (pthread_create(&(current->thread), NULL, &routine,
				(void *)current) != 0)
			return (error_message("Error", philo_list));
		if (current == philo_list->last)
			break ;
		current = current->next;
	}
	current2 = current;
	current = philo_list->first;
	while (current)
	{
		if (check(current))
			break ;
		current = current->next;
	}
	join_threads(current2, philo_list);
	return (0);
}
