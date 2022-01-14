#include <time.h>
#include <stdio.h>
#include <locale.h>

int main()
{
	char str[128];
	const size_t max = 100;
	const int baseyear = 1900;
	const char *format = "%A, %d de %B de %Y, %H:%M";

	setlocale(LC_ALL, "es_ES");
	
	time_t t = time(NULL);
	struct tm * lt = localtime(&t);
	
	size_t l = strftime(str, max, format, lt);

	printf("%s\n", str);

	return 0;
}