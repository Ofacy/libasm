#include "stdio.h"
#include "string.h"
#include "stdlib.h"

char *ft_strcpy(char *dest, char *src);

int test_buffer_overflow() {
	char buffer[1];
	char *big_buff = malloc(20000);

	memset(big_buff, 'B', 20000);
	big_buff[19999] = '\0';
	ft_strcpy(buffer, big_buff);
	free(big_buff);
	return 1;
}