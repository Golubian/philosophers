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

typedef struct s_philo
{
	size_t			id;
	pthread_mutex_t	my_fork;
	pthread_mutex_t	next_fork;
}	t_philo;

typedef struct s_game_data
{
	pthread_t		*threads;

	size_t			number_of_philosophers;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			time_to_die;
	size_t			number_of_times_each_philosopher_must_eat;
	size_t			time_started;
	pthread_mutex_t	death_mutex;
}	t_game_data;

t_philo	*philosopher_new(size_t id);

#endif