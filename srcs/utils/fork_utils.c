/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:16:42 by gachalif          #+#    #+#             */
/*   Updated: 2024/05/06 15:09:51 by gachalif         ###   ########.fr       */
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
			philos[i]->next_fork = NULL;
		else
		{
			philos[i]->next_fork = philos[(i + 1) % \
number_of_philosophers]->my_fork;
		}
		i++;
	}
}

int	check_forks_busy(t_philo *philo)
{
	int	busy;

	busy = 0;
	pthread_mutex_lock(&(philo->my_fork->fork_mutex));
	if ((philo->my_fork->fork_busy) == 1)
		busy = 1;
	pthread_mutex_unlock(&(philo->my_fork->fork_mutex));
	pthread_mutex_lock(&(philo->next_fork->fork_mutex));
	if ((philo->next_fork->fork_busy) == 1)
		busy = 1;
	pthread_mutex_lock(&(philo->next_fork->fork_mutex));
	return (busy);
}

int	forks_try_get(t_philo *philo)
{
	if (philo->next_fork == NULL)
		return (ft_sleep(philo->data->time_to_die, philo));
	while (check_forks_busy(philo) == 1)
	{
		if (ft_sleep(1, philo) == 1)
			return (1);
	}
	pthread_mutex_lock(&(philo->my_fork->fork_mutex));
	(philo->my_fork->fork_busy) = 1;
	pthread_mutex_lock(&(philo->my_fork->fork_mutex));
	pthread_mutex_lock(&(philo->next_fork->fork_mutex));
	(philo->next_fork->fork_busy) = 1;
	pthread_mutex_unlock(&(philo->next_fork->fork_mutex));
	return (0);
}
