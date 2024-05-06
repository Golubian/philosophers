/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:50:52 by gachalif          #+#    #+#             */
/*   Updated: 2024/05/06 15:12:27 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	cleanup_philos(t_game_data *data, t_philo **philos)
{
	size_t	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		pthread_mutex_destroy(&(philos[i]->my_fork->fork_mutex));
		free(philos[i]->my_fork);
		free(philos[i]);
		i++;
	}
	free(philos);
}

static void	cleanup_data(t_game_data *data)
{
	pthread_mutex_destroy(&(data->write_mutex));
	pthread_mutex_destroy(&(data->done_eating_mutex));
	free(data);
}

void	philos_memory_mutex_cleanup(t_game_data *data, t_philo **philos)
{
	cleanup_philos(data, philos);
	cleanup_data(data);
}
