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

void	philo_write(char *str, t_philo *philo)
{
	pthread_mutex_t	*write_mutex;
	size_t			id;
	size_t			philos_done;

	philos_done = get_philos_done_eating(philo->data);
	write_mutex = &(philo->data->write_mutex);
	if (!philo)
		return ;
	id = philo->id;
	if (philos_done >= philo->data->number_of_philosophers)
		return ;
	pthread_mutex_lock(write_mutex);
	if (philo->data->death_flag == 0 && \
philos_done < philo->data->number_of_philosophers)
		printf("%lu	%lu %s", get_us(philo->data) / 1000, id, str);
	pthread_mutex_unlock(write_mutex);
}

t_philo	*philosopher_new(size_t id, t_game_data *data)
{
	t_philo			*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->id = id;
	philo->my_fork = malloc(sizeof(t_fork));
	if (!philo->my_fork)
		return (philosopher_free(philo), NULL);
	philo->my_fork->fork_busy = 0;
	pthread_mutex_init(&(philo->my_fork->fork_mutex), NULL);
	philo->data = data;
	philo->last_meal = 0;
	return (philo);
}

void	*philo_live(void *arg)
{
	t_philo	*philo;
	size_t	count;

	count = 0;
	philo = (t_philo *) arg;
	while (get_us(NULL) < philo->data->time_started)
		;
	while (get_philos_done_eating(philo->data) < \
philo->data->number_of_philosophers)
	{
		philo_write("is thinking\n", philo);
		if (philo_wait_start(philo, count))
			return (0);
		if (forks_try_get(philo))
			return (0);
		if (philo_eat(philo))
			return (0);
		count++;
		if (philo_check_if_done_eating(philo, count))
			return (0);
		philo_write("is sleeping\n", philo);
		if (ft_sleep(philo->data->time_to_sleep, philo))
			return (0);
	}
	return (0);
}

pthread_t	*philosopher_init(t_philo *philo)
{
	if (pthread_create(&(philo->thread), NULL, philo_live, (void *) philo) != 0)
		return (write(STDERR_FILENO, "Error starting thread", 22), NULL);
	return (write(STDOUT_FILENO, "Thread started\n", 16), &(philo->thread));
}
