#include <stdio.h>
#include <time.h>

int main()
{
	time_t t = time(NULL);
	struct tm *dateInfo = localtime(&t);
	
	printf("Currente year: %d\n", 1900+dateInfo->tm_year);

	return 0;
}