#include "stdio.h"
#include "string.h"
#include "unistd.h"
#include <errno.h>

ssize_t ft_read(int fd, void *buf, size_t nbyte);

int test_basic() {
	int fds[2];

	pipe(fds);
	write(fds[1], "Hello, World!\nThis is a test of ft_read.\n", 41);
	char buffer[256];

	if (ft_read(fds[0], buffer, 256) != 41) {
		fprintf(stderr, "ft_read failed: expected to read 41 bytes, got %zd\n", ft_read(fds[0], buffer, 256));
		fprintf(stderr, "errno: %d\n", errno);
		return 1;
	}
	buffer[41] = '\0';
	write(1, buffer, 41);
	return 0;
}
