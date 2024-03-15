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
	
	free(data);
}
