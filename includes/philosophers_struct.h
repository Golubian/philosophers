#ifndef PHILOSOPHERS_STRUCT_H
# define PHILOSOPHERS_STRUCT_H

#include "philosophers.h"


typedef struct s_philo {

	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
}	t_philo;

typedef	struct s_game_data {
	pthread_mutex_t	death_mutex;

	size_t	number_of_philosophers;
	size_t	time_to_eat;
	size_t	time_to_sleep;
	size_t	number_of_times_each_philosopher_must_eat;
	size_t	time_started;
	
}	t_game_data;


#endif