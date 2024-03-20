/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:16:42 by gachalif          #+#    #+#             */
/*   Updated: 2024/03/19 13:47:13 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// Sets the fork values for all philos to be the next philo's fork.
void	forks_init(t_philo **philos, int number_of_philosophers)
{
	int i;
	
	i = 0;
	while (i < number_of_philosophers)
	{
		philos[i]->next_fork = philos[(i + 1) % number_of_philosophers]->my_fork;
		i++;
	}
}

int	fork_try_get(pthread_mutex_t *fork)
{
	return (pthread_mutex_lock(fork));
}