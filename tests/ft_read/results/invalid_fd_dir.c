#include "stdio.h"
#include "string.h"
#include "unistd.h"
#include "errno.h"
#include "fcntl.h"

ssize_t ft_read(int fd, void *buf, size_t nbyte);

int test_invalid_fd_dir() {
	char buf[14];
	int fd = open(".", O_RDONLY);
	if (ft_read(fd, buf, 14) != -1 || errno != EISDIR) {
		dprintf(2, "ft_read failed: expected -1 for invalid fd, got %zd\n", ft_read(fd, buf, 14));
		return 1;
	}
	return 0;
}
