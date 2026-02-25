#include "stdio.h"
#include "string.h"
#include "unistd.h"
#include <errno.h>
#include <stdlib.h>

char *ft_strdup(const char *s);

int test_basic() {
	char *dup = ft_strdup("Hello, World!");
	if (dup == NULL) {
		printf("ft_strdup failed: returned NULL\n");
		return 1;
	}
	if (strcmp(dup, "Hello, World!") != 0) {
		printf("ft_strdup failed: expected 'Hello, World!', got '%s'\n", dup);
		free(dup);
		return 1;
	}
	free(dup);
	return 0;
}
