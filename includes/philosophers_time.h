/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_time.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:57:54 by gachalif          #+#    #+#             */
/*   Updated: 2024/03/15 13:57:54 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_TIME_H
# define PHILOSOPHERS_TIME_H

# include "philosophers.h"

size_t	get_ms(t_game_data *data);
int ft_sleep(size_t time, t_philo *philo);

#endif