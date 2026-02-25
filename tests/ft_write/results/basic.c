#include "stdio.h"
#include "string.h"
#include "unistd.h"

ssize_t ft_write(int fd, const void *buf, size_t count);

int test_basic() {
	if (ft_write(1, "Hello, World!\n", 14) != 14) {
		return 1;
	}
	if (ft_write(1, "This is a test of ft_write.\n", 28) != 28) {
		return 1;
	}
	return 0;
}
