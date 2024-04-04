/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_actions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:02:33 by gachalif          #+#    #+#             */
/*   Updated: 2024/04/04 14:53:27 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philo_eat(t_philo *philo)
{
	philo_write("has taken a fork\n", philo);
	philo_write("has taken a fork\n", philo);
	philo_write("is eating\n", philo);
	philo->last_meal = get_us(philo->data);
	ft_sleep(philo->data->time_to_eat, philo);
	*(philo->fork_busy) = 0;
	*(philo->next_fork_busy) = 0;
	pthread_mutex_unlock(philo->my_fork);
	pthread_mutex_unlock(philo->next_fork);
	return (0);
}

int	philo_wait_start(t_philo *philo, size_t count)
{
	if (count != 0)
		return (0);
	if (philo->id % 2 == 1)
		if (ft_sleep(philo->data->time_to_eat, philo))
			return (1);
	if (philo->id == 0 && \
philo->data->number_of_philosophers % 2 == 1)
		if (ft_sleep(philo->data->time_to_eat * 2, philo))
			return (1);
	return (0);
}

int	philo_check_if_done_eating(t_philo *philo, size_t count)
{
	if (count == philo->data->number_of_times_each_philosopher_must_eat)
	{
		pthread_mutex_lock(philo->data->done_eating_mutex);
		philo->data->philos_done_eating += 1;
		pthread_mutex_unlock(philo->data->done_eating_mutex);
	}
	return (philo->data->number_of_philosophers == \
philo->data->philos_done_eating);
}
