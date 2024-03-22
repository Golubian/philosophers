/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_threads.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:00:15 by gachalif          #+#    #+#             */
/*   Updated: 2024/03/22 14:23:57 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_THREADS_H
# define PHILOSOPHERS_THREADS_H

# include "philosophers.h"

t_philo	**philos_thread_create(t_game_data *data);
int		philos_thread_init(t_philo **philos, t_game_data *data);
int		philos_thread_await(t_philo **philos, t_game_data *data);

#endif