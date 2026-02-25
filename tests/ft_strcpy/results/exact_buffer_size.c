#include "stdio.h"
#include "string.h"

char *ft_strcpy(char *dest, char *src);

int test_exact_size() {
	char buffer[14];

	if (strcmp(ft_strcpy(buffer, "Hello, World!"), "Hello, World!") != 0) {
		printf("ft_strcpy failed: expected 'Hello, World!', got '%s'\n", buffer);
		return 1;
	}
	return 0;
}
