#include "stdio.h"
#include "string.h"
#include "unistd.h"
#include <errno.h>
#include <stdlib.h>

#include "tests.h"

void ft_list_push_front(t_list **begin_list, void *data);
int ft_list_size(t_list *first);

int test_empty() {
	t_list *head = NULL;

	if (ft_list_size(head) != 0) {
		printf("ft_list_size failed: expected 0, got %d\n", ft_list_size(head));
		return 1;
	}
	return 0;
}
