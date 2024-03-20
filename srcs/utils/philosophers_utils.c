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

void	philosopher_free(t_philo *philo)
{
	if (!philo)
		return ;
	if (philo->my_fork)
		free(philo->my_fork);
	if (philo->next_fork)
		free(philo->next_fork);
	free(philo);
}

int	philo_survives(t_philo *philo)
{
}

t_philo	*philosopher_new(size_t id, t_game_data *data)
{
	t_philo			*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->id = id;
	philo->my_fork = malloc(sizeof(pthread_mutex_t));
	if (!philo->my_fork)
		return (philosopher_free(philo), NULL);
	philo->next_fork = malloc(sizeof(pthread_mutex_t));
	if (!philo->next_fork)
		return (philosopher_free(philo), NULL);
	if (pthread_mutex_init(philo->my_fork, NULL) != 0)
		return (philosopher_free(philo), NULL);
	philo->data = data;
	return (philo);
}

void	*philo_live(void *arg)
{
	t_philo *philo;


	philo = (t_philo *) arg;
	size_t count = 0;
	while (count < philo->data->number_of_times_each_philosopher_must_eat)
	{
		printf("%8lu	%lu is thinking\n", get_ms(philo->data), philo->id);
		if (philo->id % 2 == 1 && count == 0)
			ft_sleep(philo->data->time_to_eat);
		while (fork_try_get(philo->my_fork) != 0)
			;
		printf("%8lu	%lu has taken a fork\n", get_ms(philo->data), philo->id);
		while (fork_try_get(philo->next_fork) != 0)
			;
		printf("%8lu	%lu has taken a fork\n", get_ms(philo->data), philo->id);
		printf("%8lu	%lu is eating\n", get_ms(philo->data), philo->id);
		ft_sleep(philo->data->time_to_eat);
		philo->last_meal = get_ms(philo->data);
		pthread_mutex_unlock(philo->my_fork);
		pthread_mutex_unlock(philo->next_fork);
		printf("%8lu	%lu is sleeping\n", get_ms(philo->data), philo->id);
		ft_sleep(philo->data->time_to_sleep);
		count++;
	}

	return (0);
}

pthread_t	*philosopher_init(t_philo *philo)
{
	if (pthread_create(&(philo->thread), NULL, philo_live, (void *) philo) != 0)
		return (write(STDERR_FILENO, "Error starting thread", 22), NULL);
	return (write(STDOUT_FILENO, "Thread started\n", 16), &(philo->thread));
}
