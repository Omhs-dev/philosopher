/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettime.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 03:31:24 by ohamadou          #+#    #+#             */
/*   Updated: 2024/02/10 00:18:20 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

uint64_t ft_gettime_microsec()
{
	struct timeval curren_time;

	gettimeofday(&curren_time, NULL);
	return ((curren_time.tv_sec * (uint64_t)1000000) + curren_time.tv_usec);
}

uint64_t ft_gettime_millisec()
{
	// if (gettimeofday(&time, NULL) == -1)
	// 	printf("gettimeofday : error\n");
	return (ft_gettime_microsec() / 1000);
}

// int main()
// {
// 	printf("%u\n", ft_gettime_microsec());
// 	printf("%f\n", ft_gettime_millisec());
// 	return (0);
// }
