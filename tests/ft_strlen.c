#include "assert.h"
#include "stdio.h"

int ft_strlen(char *str);

int main() {
	assert(ft_strlen("") == 0);
	assert(ft_strlen("abc") == 3);
	assert(ft_strlen("Hello, World!") == 13);
	assert(ft_strlen("     ") == 5);
	assert(ft_strlen("THIS WORKS, RIGHT?!") == 19);
	printf("ft_strlen OK\n");
}