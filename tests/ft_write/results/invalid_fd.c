#include "stdio.h"
#include "string.h"
#include "unistd.h"
#include "errno.h"

ssize_t ft_write(int fd, const void *buf, size_t count);

int test_invalid_fd() {
	if (ft_write(13232, "Hello, World!\n", 14) != -1) {
		dprintf(2, "ft_write failed: expected -1 for invalid fd, got %zd\n", ft_write(13232, "Hello, World!\n", 14));
		return 1;
	}
	return 0;
}
