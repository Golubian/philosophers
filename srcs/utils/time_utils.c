/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:47:06 by gachalif          #+#    #+#             */
/*   Updated: 2024/03/15 13:47:06 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

size_t	get_us(t_game_data *data)
{
	struct timeval	timeval;
	size_t			us;

	gettimeofday(&timeval, NULL);
	us = ((timeval.tv_sec * 1000000) + (timeval.tv_usec));
	if (data && data->time_started)
	{
		us -= data->time_started;
	}
	return (us);
}

int ft_sleep(size_t time_to_wait, t_philo *philo)
{
	size_t			us_started;

	us_started = get_us(NULL);
	while (get_us(NULL) < us_started + time_to_wait)
	{
		if (philo->data->death_flag == 1 || philo->data->philos_done_eating == philo->data->number_of_philosophers)
			return (1);
		else if (get_us(philo->data) > ((philo->last_meal) + philo->data->time_to_die))
		{
			pthread_mutex_lock(philo->data->write_mutex);
			if (philo->data->death_flag == 0)
				printf("%lu	%lu has died\n", get_us(philo->data)/1000, philo->id);
			philo->data->death_flag = 1;
			pthread_mutex_unlock(philo->data->write_mutex);
			return (1);
		}
	}
	return (0);
}
