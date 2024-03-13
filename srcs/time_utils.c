# include "philosophers.h"

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