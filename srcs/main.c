
#include "philosophers.h"

int main(void)
{
	struct timeval	*tv = malloc(sizeof(struct timeval));
	struct timeval	*new_tv = malloc(sizeof(struct timeval));
	gettimeofday(tv, NULL);

	while (!usleep(1))
	{
		gettimeofday(new_tv, NULL);
		size_t	time = ((new_tv->tv_sec * 1000) + (new_tv->tv_usec / 1000));
		time -= ((tv->tv_sec * 1000) + (tv->tv_usec / 1000));

		printf("\033[1F\033[2K%li MS\n", time);
	}
}