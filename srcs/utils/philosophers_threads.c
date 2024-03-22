/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_threads.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:57:07 by gachalif          #+#    #+#             */
/*   Updated: 2024/03/22 14:07:14 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philo	**philos_thread_create(t_game_data *data)
{
	t_philo **philos;
	size_t	i;

	philos = malloc(sizeof(t_philo *) * (data->number_of_philosophers + 1));
	if (!philos)
		return (NULL);
	i = 0;
	while (i < data->number_of_philosophers)
	{
		philos[i] = philosopher_new(i, data);
		i++;
	}
	return (philos);
}
int philos_thread_init(t_philo **philos, t_game_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		pthread_create(&(philos[i]->thread), NULL, philo_live, philos[i]);
		i++;
	}
	return (0);
}
int philos_thread_await(t_philo **philos, t_game_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		if (philos[i])
			pthread_join((philos[i]->thread), NULL);
		i++;
	}
	return (0);
}