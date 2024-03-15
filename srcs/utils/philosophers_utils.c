/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:47:20 by gachalif          #+#    #+#             */
/*   Updated: 2024/03/15 13:47:20 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philo	*philosopher_new(size_t id)
{
	t_philo			*new_philo;
	pthread_mutex_t	new_fork;

	new_philo = malloc(sizeof(t_philo));
	if (!new_philo)
		return (NULL);
	new_philo->id = id;
	new_philo->my_fork = new_fork;
	if (pthread_mutex_init(&new_fork, NULL) != 0)
		return (free(new_philo), NULL);
	return (new_philo);
}

void	philo_live(void *arg)
{
	
}

pthread_t	philosopher_init(t_philo *philo, t_game_data *data)
{
	pthread_t	new_thread;

	if (pthread_create(&new_thread, NULL, &philo_live, philo) != 0);
		return (write(STDERR_FILENO, "Error starting thread", 22), NULL);
	return (new_thread);
}
