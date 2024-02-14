/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 08:18:55 by ohamadou          #+#    #+#             */
/*   Updated: 2024/02/14 05:28:05 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int input(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			return (1);
		else
			break;
		i++;
	}
	return (0);
}

int check_input(char *str)
{
    while(*str)
    {
        if (!input(str))
        {
            return (1);
            break ;
        }
        else
            str++;
    }
    return (0);
}

int all_input(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		printf("Error: Invalid input\n");
		return (1);
	}
	if (check_input(argv[1]) == 1
		||check_input(argv[2]) == 1
		||check_input(argv[3]) == 1
		||check_input(argv[4]) == 1)
	{
		printf("Error: Invalid input\n");
		return (1);
	}
	return (0);
}

int check_values(int argc, t_data *data)
{
	if (argc == 6)
	{
		if (data->max_meals_eaten == 0)
			return (1);
		if (data->max_meals_eaten < 0)
		{
			printf("Error: Invalid values\n");
			return (1);
		}
	}
	if (data->numbers_of_philo > 200
		|| data->numbers_of_philo <= 0)
		// || data->time_die < 0
		// || data->time_eat < 0
		// || data->time_sleep < 0)
	{
		printf("Error: Invalid values\n");
		return (1);
	}
	return (0);
}
