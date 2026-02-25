#include "stdio.h"
#include "string.h"
#include "unistd.h"
#include "errno.h"

ssize_t ft_read(int fd, void *buf, size_t nbyte);

int test_invalid_fd_errno() {
	char buf[14];
	if (ft_read(13232, buf, 14) != -1 || errno != EBADF) {
		return 1;
	}
	return 0;
}
