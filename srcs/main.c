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

int	main(void)
{
	t_game_data	*data;
	size_t philo_count;
	t_philo	**philos;

	data = malloc(sizeof(t_game_data));
	if (!data)
		return (1);
	data->time_started = get_ms(NULL);
	data->number_of_philosophers = 3;
	data->number_of_times_each_philosopher_must_eat = 10;
	data->time_to_eat = 100;
	data->time_to_sleep = 100;
	data->time_to_die = 300;
	philo_count = 0;	
	philos = malloc(sizeof(t_philo *) * (data->number_of_philosophers + 1));
	while (philo_count < data->number_of_philosophers)
	{
		philos[philo_count] = philosopher_new(philo_count, data);
		pthread_create(&(philos[philo_count]->thread), NULL, philo_live, philos[philo_count]);
		philo_count++;
	}
	forks_init(philos, data->number_of_philosophers);
	philo_count = 0;
	while (philo_count < data->number_of_philosophers)
	{
		pthread_join((philos[philo_count]->thread), NULL);
		philo_count++;
	}
	free(philos);
	free(data);
}
