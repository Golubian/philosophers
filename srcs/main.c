/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:46:49 by gachalif          #+#    #+#             */
/*   Updated: 2024/03/15 13:46:49 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(void)
{
	t_game_data	*data;

	data = malloc(sizeof(t_game_data));
	if (!data)
		return (1);
	data->time_started = get_ms(NULL);
	data->number_of_philosophers = 2;
	data->time_to_eat = 100;
	data->time_to_sleep = 100;
	data->time_to_die = 300;
	
	t_philo	**philos = malloc(sizeof(t_philo *) * (data->number_of_philosophers + 1));
	*philos = philosopher_new(0, data);
	*(philos + 1) = philosopher_new(1, data);
	forks_init(philos, data->number_of_philosophers);


	// while (1 == 1)
	// {
	// 	usleep(100000);
	// 	printf("%4lu MS\n", get_ms(data));
	// }
	philosopher_init(philosopher_new(0, data));
	philosopher_init(philosopher_new(1, data));
	//forks_init(philos, data->number_of_philosophers);
	free(data);
}
