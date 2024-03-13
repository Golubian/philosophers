
#include "philosophers.h"

int main(void)
{
	t_game_data	*data;

	data = malloc(sizeof(t_game_data));
	if (!data)
		return (1);
	data->time_started = get_ms(NULL);
	while (!usleep(1000))
	{
		printf("\033[1F\033[2K\n%30li MS", get_ms(data));
	}

	free(data);
}