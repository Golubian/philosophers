/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:56:37 by gachalif          #+#    #+#             */
/*   Updated: 2024/03/25 14:21:36 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_valid_int(char *str)
{
	size_t	i;
	size_t	bank;

	i = 0;
	bank = 0;
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (-1);
		bank *= 10;
		bank += (str[i] - 48);
		i++;
		if (i > 10)
			break ;
	}
	if (bank > 2147483647)
		return (-1);
	return (bank);
}

t_parsed_data	parse_argv(char **argv)
{
	t_parsed_data	data;
	size_t			i;

	data.parsed_data_is_valid = 0;
	i = 1;
	while (argv[i])
	{
		if (is_valid_int(argv[i]) < 0)
			return (data);
		i++;
	}
	data.number_of_philosophers = (size_t)is_valid_int(argv[1]);
	data.time_to_die = (size_t)is_valid_int(argv[2]);
	data.time_to_eat = (size_t)is_valid_int(argv[3]);
	data.time_to_sleep = (size_t)is_valid_int(argv[4]);
	if (argv[5])
		data.number_of_times_each_philosopher_must_eat = \
	(size_t)is_valid_int(argv[5]);
	else
		data.number_of_times_each_philosopher_must_eat = -1;
	data.parsed_data_is_valid = 1;
	return (data);
}
