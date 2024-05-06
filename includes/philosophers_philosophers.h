/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_struct.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:48:00 by gachalif          #+#    #+#             */
/*   Updated: 2024/03/15 13:48:00 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_PHILOSOPHERS_H
# define PHILOSOPHERS_PHILOSOPHERS_H

# include "philosophers.h"

typedef struct s_game_data
{
	pthread_t		*threads;

	size_t			number_of_philosophers;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			time_to_die;
	size_t			number_of_times_each_philosopher_must_eat;
	size_t			time_started;
	size_t			philos_done_eating;
	pthread_mutex_t	done_eating_mutex;
	pthread_mutex_t	write_mutex;
	char			death_flag;
	pthread_mutex_t	death_mutex;
}	t_game_data;

typedef struct s_fork
{
	int				fork_busy;
	pthread_mutex_t	fork_mutex;
}	t_fork;

typedef struct s_philo
{
	t_game_data		*data;
	pthread_t		thread;
	size_t			id;
	size_t			last_meal;
	t_fork			*my_fork;
	t_fork			*next_fork;
}	t_philo;

//HANDLERS
t_philo		*philosopher_new(size_t id, t_game_data *data);
pthread_t	*philosopher_init(t_philo *philo);
void		*philo_live(void *arg);

//UTILS
void		philo_write(char *str, t_philo *philo);

//ACTIONS
int			philo_wait_start(t_philo *philo, size_t count);
int			philo_eat(t_philo *philo);
int			philo_check_if_done_eating(t_philo *philo, size_t count);

#endif