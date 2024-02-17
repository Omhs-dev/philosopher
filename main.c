/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:26:58 by ohamadou          #+#    #+#             */
/*   Updated: 2024/02/17 09:34:37 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

int	main(int argc, char **argv)
{
	t_data			*data;
	t_philo_list	*list;

	if (all_input(argc, argv) == 1)
		return (1);
	data = init_data(argc, argv);
	if (check_values(argc, data) == 1)
		return (1);
	list = creat_list(argv, &data);
	if (!data || !list)
		return (1);
	create_and_start_threads(list);
	destroy_mutex(list);
	ft_free(list);
	free(data);
	data = NULL;
	return (0);
}
	// system("leaks philo");
