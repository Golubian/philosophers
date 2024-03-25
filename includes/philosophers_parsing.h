/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_parsing.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:51:32 by gachalif          #+#    #+#             */
/*   Updated: 2024/03/25 13:54:58 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_PARSING_H
# define PHILOSOPHERS_PARSING_H

# include "philosophers.h"

typedef struct s_parsed_data
{
	char	parsed_data_is_valid;
	size_t	number_of_philosophers;
	size_t	number_of_times_each_philosopher_must_eat;
	size_t	time_to_eat;
	size_t	time_to_sleep;
	size_t	time_to_die;
}	t_parsed_data;

t_parsed_data	parse_argv(char **argv);

#endif