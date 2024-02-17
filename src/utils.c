/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:28:50 by ohamadou          #+#    #+#             */
/*   Updated: 2024/02/17 09:34:24 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_atoi(char *str)
{
	int	sign;
	int	opr;

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

void	ft_free(t_philo_list *list)
{
	t_philo	*current;
	t_philo	*temp;

	current = list->first;
	while (current != NULL)
	{
		temp = current;
		if (current == list->last)
		{
			free(temp);
			temp = NULL;
			break ;
		}
		else
		{
			current = current->next;
			free(temp);
			temp = NULL;
		}
	}
	free(list);
	list = NULL;
}

void	destroy_mutex(t_philo_list *list)
{
	pthread_mutex_destroy(&(list->first->fork_right));
	pthread_mutex_destroy(&(list->first->data->printf));
	pthread_mutex_destroy(&(list->first->data->time));
	pthread_mutex_destroy(&(list->first->data->check_death));
	pthread_mutex_destroy(&(list->first->data->meals_eaten));
}

int	error_message(char *str, t_philo_list *list)
{
	printf("%s\n", str);
	destroy_mutex(list);
	ft_free(list);
	return (1);
}

void	ft_usleep(uint64_t millsec)
{
	uint64_t	time;

	time = ft_gettime_millisec() + millsec;
	while (ft_gettime_millisec() != time)
		usleep(500);
}
