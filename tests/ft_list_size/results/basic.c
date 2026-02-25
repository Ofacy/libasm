#include "stdio.h"
#include "string.h"
#include "unistd.h"
#include <errno.h>
#include <stdlib.h>

#include "tests.h"

void ft_list_push_front(t_list **begin_list, void *data);
int ft_list_size(t_list *first);

int test_basic() {
	t_list *head = NULL;

	for (int i = 0; i < 10; i++) {
		ft_list_push_front(&head, NULL);
	}
	if (ft_list_size(head) != 10) {
		printf("ft_list_size failed: expected 10, got %d\n", ft_list_size(head));
		return 1;
	}

	return 0;
}
