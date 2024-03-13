#ifndef PHILOSOPHERS_STRUCT_H
# define PHILOSOPHERS_STRUCT_H

#include "philosophers.h"


typedef struct s_philo {

	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
}	t_philo;

typedef	struct s_game_data {
	size_t	time_started;
	
}	t_game_data;


#endif