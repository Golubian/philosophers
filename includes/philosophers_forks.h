/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_forks.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:19:05 by gachalif          #+#    #+#             */
/*   Updated: 2024/03/18 13:43:45 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_FORK_H
# define PHILOSOPHERS_FORK_H

# include "philosophers.h"

void	forks_init(t_philo **philos, int number_of_philosophers);
int		fork_try_get(pthread_mutex_t *fork);

#endif