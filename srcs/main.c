/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:46:49 by gachalif          #+#    #+#             */
/*   Updated: 2024/03/15 13:46:49 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//Parse data from strings
t_game_data	*data_init(void)
{
	t_game_data	*data;

	data = malloc(sizeof(t_game_data));
	if (!data)
		return (0);
	data->write_mutex = malloc(sizeof(pthread_mutex_t));
	if (!data->write_mutex)
		return (free(data), NULL);
	data->done_eating_mutex = malloc(sizeof(pthread_mutex_t));
	if (!data->done_eating_mutex)
		return (free(data->write_mutex), free(data), NULL);
	data->time_started = get_us(NULL) + 1000000;
	data->number_of_philosophers = 1;
	data->number_of_times_each_philosopher_must_eat = 1;
	data->time_to_eat = 200 * 1000;
	data->time_to_sleep = 200 * 1000;
	data->time_to_die = 800 * 1000;
	data->death_flag = 0;
	data->philos_done_eating = 0;
	pthread_mutex_init(data->write_mutex, NULL);
	pthread_mutex_init(data->done_eating_mutex, NULL);
	return (data);
}

int	main(void)
{
	t_game_data	*data;
	t_philo		**philos;

	data = data_init();
	philos = philos_thread_create(data);
	forks_init(philos, data->number_of_philosophers);
	philos_thread_init(philos, data);
	philos_thread_await(philos, data);
	philos_memory_mutex_cleanup(data, philos);
}
// add cleanup