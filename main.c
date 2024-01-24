/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:26:58 by ohamadou          #+#    #+#             */
/*   Updated: 2024/01/24 05:14:35 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	(void)argc;
	t_philo_list *list;
	t_philo *current;
	uint64_t start_time;
	int j;

	j = 0;
	start_time = ft_gettime_millisec();
	list = creat_list(argv);
	current = list->first;
	printf("starting time %llu\n", 	start_time);
	while (current)
	{
		// printf("philo number %d : time :%llu will try to take his right fork\n", i, ft_gettime_millisec() - start_time);
		pthread_mutex_lock(&(current->fork_right));
		printf("philo number %d: time :%llu took his right fork\n", j, ft_gettime_millisec() - start_time);
		// printf("philo number %d : time :%llu will try to take his left fork\n", i, ft_gettime_millisec() - start_time);
		pthread_mutex_lock(&*(current->fork_left));
		printf("philo number %d: time :%llu took his left fork\n", j, ft_gettime_millisec() - start_time);
		// printf("philo number %d : time :%llu will drop his right fork\n", i, ft_gettime_millisec() - start_time);
		pthread_mutex_unlock(&(current->fork_right));
		// printf("philo number %d : time :%llu drop his right fork\n", i, ft_gettime_millisec() - start_time);
		// printf("philo number %d : time :%llu will drop his left fork\n", i, ft_gettime_millisec() - start_time);
		pthread_mutex_unlock(&*(current->fork_left));
		// printf("philo number %d : time :%llu drop his left fork\n", i, ft_gettime_millisec() - start_time);
		// printf("im philo = %d\n",i);
		current = current->prev;
		if (current == list->first)
			break;
		j++;
		j = j % ft_atoi(argv[1]);
		if (j == 50)
			break;		
	}
	printf("size = %zu\n",list->size);
	return (0);
}
