#include "stdio.h"
#include "string.h"

int ft_strcmp(const char *s1, const char *s2);

int test_basic() {
	if (ft_strcmp("Hello, World!", "Hello, World!") != 0) {
		printf("ft_strcmp failed: expected 0, got %d\n", ft_strcmp("Hello, World!", "Hello, World!"));
		return 1;
	}
	if (ft_strcmp("", "") != 0) {
		printf("ft_strcmp failed: expected 0, got %d\n", ft_strcmp("", ""));
		return 1;
	}
	if (ft_strcmp("abc", "abc") != 0) {
		printf("ft_strcmp failed: expected 0, got %d\n", ft_strcmp("abc", "abc"));
		return 1;
	}
	if (ft_strcmp("abc", "abd") >= 0) {
		printf("ft_strcmp failed: expected negative value, got %d\n", ft_strcmp("abc", "abd"));
		return 1;
	}
	if (ft_strcmp("abd", "abc") <= 0) {
		printf("ft_strcmp failed: expected positive value, got %d\n", ft_strcmp("abd", "abc"));
		return 1;
	}
	return 0;
}
