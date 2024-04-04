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
t_game_data	*data_init(t_parsed_data parsed_data)
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
	data->number_of_philosophers = parsed_data.number_of_philosophers;
	data->number_of_times_each_philosopher_must_eat = \
parsed_data.number_of_times_each_philosopher_must_eat;
	data->time_to_eat = parsed_data.time_to_eat * 1000;
	data->time_to_sleep = parsed_data.time_to_sleep * 1000;
	data->time_to_die = parsed_data.time_to_die * 1000;
	data->death_flag = 0;
	data->philos_done_eating = 0;
	pthread_mutex_init(data->write_mutex, NULL);
	pthread_mutex_init(data->done_eating_mutex, NULL);
	return (data);
}

int	main(int argc, char **argv)
{
	t_game_data		*data;
	t_philo			**philos;
	t_parsed_data	parsed;

	if (argc <= 4 || parse_argv(argv).parsed_data_is_valid == 0)
		return (printf("Not enough arguments or arguments invalid.\n\nUsage:\n./philo number_of_philosophers\
 time_to_die time_to_eat time_to_sleep \
[number_of_times_each_philosopher_must_eat]"), 1);
	parsed = parse_argv(argv);
	if (parsed.number_of_times_each_philosopher_must_eat == 0)
		return (printf("Not enough arguments or arguments invalid.\n\nUsage:\n./philo number_of_philosophers\
 time_to_die time_to_eat time_to_sleep \
[number_of_times_each_philosopher_must_eat]"), 1);
	data = data_init(parsed);
	philos = philos_thread_create(data);
	forks_init(philos, data->number_of_philosophers);
	philos_thread_init(philos, data);
	philos_thread_await(philos, data);
	philos_memory_mutex_cleanup(data, philos);
}
