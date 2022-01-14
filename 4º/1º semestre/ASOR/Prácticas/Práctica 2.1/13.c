#include <stdio.h>
#include <time.h>
#include <sys/time.h>

int main()
{
	int num = 0;
	struct timeval startTime, endTime;
	
	gettimeofday(&startTime, NULL);
	for (int i = 0; i < 1000000; i++)
	{
		num++;
	}
	gettimeofday(&endTime, NULL);

	suseconds_t elapsedMicroseconds = endTime.tv_usec - startTime.tv_usec;
	printf("Elapsed time in microseconds: %ld\n", elapsedMicroseconds);
	
	return 0;
}