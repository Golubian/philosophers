/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_forks.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:19:05 by gachalif          #+#    #+#             */
/*   Updated: 2024/03/22 14:23:53 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_FORKS_H
# define PHILOSOPHERS_FORKS_H

# include "philosophers.h"

void	forks_init(t_philo **philos, int number_of_philosophers);
int		fork_try_get(t_philo *philo, pthread_mutex_t *fork);

#endif