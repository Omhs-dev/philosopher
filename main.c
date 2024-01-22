/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:26:58 by ohamadou          #+#    #+#             */
/*   Updated: 2024/01/22 20:31:20 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	(void)argc;
	t_philo_list *list;
	t_philo *current;

	int i = 1;
	list = creat_list(argv);
	current = list->first;
	while (current)
	{
		pthread_mutex_lock(&(current->fork_right));
		pthread_mutex_lock(&*(current->fork_left));
		pthread_mutex_unlock(&(current->fork_right));
		pthread_mutex_unlock(&*(current->fork_left));
		printf("im philo = %d\n",i);
		current = current->prev;
		i++;
		if (i == 200)
			break;
	}
	printf("size = %zu\n",list->size);
	return (0);
}
