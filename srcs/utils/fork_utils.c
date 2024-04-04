/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:16:42 by gachalif          #+#    #+#             */
/*   Updated: 2024/04/04 14:39:35 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// Sets the fork values for all philos to be the next philo's fork.
void	forks_init(t_philo **philos, int number_of_philosophers)
{
	int	i;

	i = 0;
	while (i < number_of_philosophers)
	{
		if (number_of_philosophers == 1)
		{
			philos[i]->next_fork = NULL;
			philos[i]->next_fork_busy = NULL;
		}
		else
		{
			philos[i]->next_fork = philos[(i + 1) % \
number_of_philosophers]->my_fork;
			philos[i]->next_fork_busy = philos[(i + 1) % \
number_of_philosophers]->fork_busy;
		}
		i++;
	}
}

int	forks_try_get(t_philo *philo)
{
	pthread_mutex_t	*fork;
	pthread_mutex_t	*next_fork;

	if (!philo->next_fork_busy)
		return (ft_sleep(philo->data->time_to_die, philo));
	while (*(philo->fork_busy) != 0 && *(philo->next_fork_busy) != 0 && \
	(philo->data->philos_done_eating < philo->data->number_of_philosophers))
	{
		if (ft_sleep(1, philo) == 1)
			return (1);
	}
	fork = philo->my_fork;
	next_fork = philo->next_fork;
	if (fork && next_fork && (philo->data->philos_done_eating < \
philo->data->number_of_philosophers))
	{
		if (pthread_mutex_lock(fork) || pthread_mutex_lock(next_fork))
			return (1);
		*(philo->fork_busy) = 1;
		*(philo->next_fork_busy) = 1;
		return (0);
	}
	return (1);
}
