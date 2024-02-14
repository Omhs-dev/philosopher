/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:26:58 by ohamadou          #+#    #+#             */
/*   Updated: 2024/02/14 05:25:19 by ohamadou         ###   ########.fr       */
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
		return (1);
	create_and_start_threads(list);
	printf("time: %llu\n", data->time_die);
	// printf("size = %zu\n",list->size);
	destroy_mutex(list);
	free(data);
	ft_free(list);
	// system("leaks check");
	return (0);
}
