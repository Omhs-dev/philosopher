/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettime.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 03:31:24 by ohamadou          #+#    #+#             */
/*   Updated: 2024/01/24 04:41:17 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

uint64_t ft_gettime_microsec()
{
	uint64_t return_value;
	
	struct timeval curren_time;
	gettimeofday(&curren_time, NULL);
	return_value = (curren_time.tv_sec * 1000000) + curren_time.tv_usec;
	return (return_value);
}

uint64_t ft_gettime_millisec()
{
	return (ft_gettime_microsec() / 1000);
}

// int main()
// {
// 	printf("%u\n", ft_gettime_microsec());
// 	printf("%f\n", ft_gettime_millisec());
// 	return (0);
// }
