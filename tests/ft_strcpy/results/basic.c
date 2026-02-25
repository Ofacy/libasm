#include "stdio.h"
#include "string.h"

char *ft_strcpy(char *dest, char *src);

int test_basic() {
	char buffer[256];

	if (strcmp(ft_strcpy(buffer, "Hello, World!"), "Hello, World!") != 0) {
		printf("ft_strcpy failed: expected 'Hello, World!', got '%s'\n", buffer);
		return 1;
	}
	if (strcmp(ft_strcpy(buffer, ""), "") != 0) {
		printf("ft_strcpy failed: expected '', got '%s'\n", buffer);
		return 1;
	}
	if (strcmp(ft_strcpy(buffer, "abc"), "abc") != 0) {
		printf("ft_strcpy failed: expected 'abc', got '%s'\n", buffer);
		return 1;
	}
	return 0;
}
