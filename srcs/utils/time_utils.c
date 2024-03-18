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

size_t	get_ms(t_game_data *data)
{
	struct timeval	timeval;
	size_t			ms;

	gettimeofday(&timeval, NULL);
	ms = ((timeval.tv_sec * 1000) + (timeval.tv_usec / 1000));
	if (data && data->time_started)
	{
		ms -= data->time_started;
	}
	return (ms);
}

void ft_sleep(size_t time_to_wait)
{
	size_t			ms_started;
	
	ms_started = get_ms(NULL);
	while (get_ms(NULL) < ms_started + time_to_wait)
		;
	return ;
}
