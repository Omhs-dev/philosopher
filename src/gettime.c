/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettime.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 03:31:24 by ohamadou          #+#    #+#             */
/*   Updated: 2024/02/17 09:23:38 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

uint64_t	ft_gettime_microsec(void)
{
	struct timeval	curren_time;

	gettimeofday(&curren_time, NULL);
	return ((curren_time.tv_sec * (uint64_t)1000000) + curren_time.tv_usec);
}

uint64_t	ft_gettime_millisec(void)
{
	return (ft_gettime_microsec() / 1000);
}
