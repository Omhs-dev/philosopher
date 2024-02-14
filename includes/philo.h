/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:25:59 by ohamadou          #+#    #+#             */
/*   Updated: 2024/02/14 04:49:31 by ohamadou         ###   ########.fr       */
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
	pthread_mutex_t check_death;
	uint64_t time_sleep;
	uint64_t time_die;
	uint64_t time_eat;
	uint64_t start_time;
	int numbers_of_philo;
	int death_status;
	int max_meals_eaten;
	int done;
} t_data;

typedef struct s_philo
{
	pthread_mutex_t fork_right;
	pthread_mutex_t *fork_left;
	t_data *data;
	pthread_t thread;
	uint64_t time_sleep;
	uint64_t time_die;
	uint64_t time_eat;
	uint64_t start_time;
	int meals_eaten;
	int eat_status;
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
t_data *init_data(int argc, char **argv);
void print_message(t_philo *philo, char *str);
void take_the_forks(t_philo *philo);
void drop_the_forks(t_philo *philo);
void is_eating(t_philo *philo);
void ft_free(t_philo_list *list);
void destroy_mutex(t_philo_list *list);
int error_message(char *str, t_philo_list *list);
void is_sleeping(t_philo *philo);
void ft_usleep(uint64_t millsec);
void is_thinking(t_philo *philo);
int check(t_philo *philo);
void error_return(void);
int check_input(char *str);
int input(char *str);
void cleanup(t_philo_list *philo_list);
// void cleanup(t_philo_list *philo_list);
int all_input(int argc, char **argv);
int check_values(int argc, t_data *data);
void free_philo(t_philo *philo);
void free_list(t_philo_list *list);

#endif
