/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:26:58 by ohamadou          #+#    #+#             */
/*   Updated: 2024/02/12 10:05:25 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_data *data;
	
	(void)argc;
	t_philo_list *list;
	if (all_input(argc, argv) == 1)
		return (1);
	data = init_data(argc, argv);
	if (check_values(argc, data) == 1)
		return (1);
	list = creat_list(argv, &data);
	if (!data || !list)
		return (0);
	// t_philo *current;
	// uint64_t start_time;
	// int j;
	// j = 0;
	// start_time = ft_gettime_millisec();
	// current = list->first;
	// printf("starting time %llu\n", 	start_time);
	create_and_start_threads(list);
	printf("time: %llu\n", data->time_die);
	// printf("size = %zu\n",list->size);
	return (0);
}
