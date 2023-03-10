/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimartin <gimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:50:23 by gimartin          #+#    #+#             */
/*   Updated: 2022/05/17 15:10:18 by gimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <stdint.h>
# include <semaphore.h>
# include <fcntl.h>

typedef struct s_context
{
	int			num_philos;
	uint64_t	time_die;
	uint64_t	time_eat;
	uint64_t	time_sleep;
	int			times_to_eat;
	int			some_die;
	int			finished;
	uint64_t	s_time;
	sem_t		*writing;
	sem_t		*meal_check;
	pthread_t	monitor;
}				t_context;

typedef struct s_philos
{
	int			id;
	pid_t		pid;
	int			dead;
	uint64_t	last_meal;
	int			times_eaten;
	int			is_dead;
	t_context	*elem;
	sem_t		*forks;
}				t_philos;

void		checks(int argc, char **argv);

void		usage(void);
void		error_args(void);
void		error_ui(void);
void		general_error(void);
void		error_too_many(void);

void		ft_putchar_err(char c);
void		ft_putstr_err(char *str);
void		ft_putendl_err(char *str);
void		die(char *str);

int			get_fork_id(int i, t_context *context);
void		get_philosophers(t_context *elem, t_philos *philos, sem_t *forks);
sem_t		*get_sem(t_context *context);

void		sit(t_context *elem);
void		philosophers(int argc, char **argv);

int			monitor_meals(t_philos *philos);
void		*monitor(void *philos);
void		take_fork(t_philos *philo);
void		born_child(t_philos *philo);

void		kill_them_all(t_philos *philos);
void		start_symposium(t_philos *philos);

uint64_t	get_time(t_philos *philo, int flag);
uint64_t	get_s_time(void);

int			ft_atoi(const char *str);
void		dont_wake_up(t_philos *philo, uint64_t time);
void		write_message(t_philos *philo, int flag);

#endif
