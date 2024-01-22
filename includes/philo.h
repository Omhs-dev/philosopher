/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:25:59 by ohamadou          #+#    #+#             */
/*   Updated: 2024/01/22 19:53:58 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>

typedef struct s_philo
{
	pthread_mutex_t fork_right;
	pthread_mutex_t *fork_left;
	char *time_eat;
	char *time_sleep;
	char *time_think;
	char *time_die;
	struct s_philo *next;
	struct s_philo *prev;
}   t_philo;

typedef struct s_philo_list
{
	t_philo *first;
	t_philo *last;
	size_t size;
}   t_philo_list;

t_philo *init_philo(char **argv);
int ft_atoi(char *str);
t_philo_list *creat_list(char **argv);
t_philo_list *init_list(void);

#endif
