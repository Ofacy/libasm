#include "stdio.h"
#include "string.h"
#include "unistd.h"
#include "errno.h"

ssize_t ft_write(int fd, const void *buf, size_t count);

int test_invalid_fd_errno() {
	if (ft_write(13232, "Hello, World!\n", 14) != -1 || errno != EBADF) {
		return 1;
	}
	return 0;
}
