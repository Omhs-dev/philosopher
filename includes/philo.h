/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:25:59 by ohamadou          #+#    #+#             */
/*   Updated: 2024/01/29 06:56:49 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>
# include <unistd.h> 

typedef struct s_data
{
	pthread_mutex_t printf;
	int time_sleep;
	// int time_think;
	int time_die;
	int time_eat;
} t_data;

typedef struct s_philo
{
	pthread_mutex_t fork_right;
	pthread_mutex_t *fork_left;
	t_data *data;
	pthread_t thread;
	int time_sleep;
	// int time_think;
	int time_die;
	int time_eat;
	int philo_number;
	struct s_philo *next;
	struct s_philo *prev;
}   t_philo;

typedef struct s_philo_list
{
	t_philo *first;
	t_philo *last;
	size_t size;
}   t_philo_list;


t_philo *init_philo(char **argv, t_data **data);
int ft_atoi(char *str);
t_philo_list *creat_list(char **argv, t_data **data);
t_philo_list *init_list(void);
uint64_t ft_gettime_microsec();
uint64_t  ft_gettime_millisec();
void *start_routine(void *ptr);
int create_and_start_threads(t_philo_list *philo_list);
void *routine(void *arg);
t_data *init_data(char **argv);

#endif
