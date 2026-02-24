#include "assert.h"
#include "stdio.h"
#include "string.h"

char *ft_strcpy(char *dest, char *src);



int main() {
	char buffer[256];

	assert(ft_strcpy(buffer, "hello") == buffer);
	assert(strcmp(buffer, "hello") == 0);
	assert(ft_strcpy(buffer, "Hello, World!") == buffer);
	assert(strcmp(buffer, "Hello, World!") == 0);
	assert(ft_strcpy(buffer, "") == buffer);
	assert(strlen(buffer) == 0);
	printf("ft_strcpy OK\n");
}