#include "stdio.h"
#include "string.h"

size_t ft_strlen(const char *s);

int test_basic() {
	if (ft_strlen("Hello, World!") != 13) {
		printf("ft_strlen failed: expected 13, got %zu\n", ft_strlen("Hello, World!"));
		return 1;
	}
	if (ft_strlen("") != 0) {
		printf("ft_strlen failed: expected 0, got %zu\n", ft_strlen(""));
		return 1;
	}
	if (ft_strlen("abc") != 3) {
		printf("ft_strlen failed: expected 3, got %zu\n", ft_strlen("abc"));
		return 1;
	}
	return 0;
}
