#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "md5.hpp"

int main(int argc, char **argv)
{
	if (argc < 2) {
		printf("usage: %s 'string'\n", argv[0]);
		return 1;
	}

	char *msg = argv[1];
	size_t len = strlen(msg);

	uint32_t h0, h1, h2, h3;

	md5(&h0, &h1, &h2, &h3, msg, len);

	// display result
	printf("String=%s md5=", msg);
	uint8_t *p;
	p=(uint8_t *)&h0;
	printf("%2.2x%2.2x%2.2x%2.2x", p[3], p[2], p[1], p[0]);
	p=(uint8_t *)&h1;
	printf("%2.2x%2.2x%2.2x%2.2x", p[3], p[2], p[1], p[0]);
	p=(uint8_t *)&h2;
	printf("%2.2x%2.2x%2.2x%2.2x", p[3], p[2], p[1], p[0]);
	p=(uint8_t *)&h3;
	printf("%2.2x%2.2x%2.2x%2.2x\n", p[3], p[2], p[1], p[0]);

	return 0;
}