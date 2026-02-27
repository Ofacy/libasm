#include "stdio.h"
#include "string.h"
#include "unistd.h"
#include <errno.h>
#include <stdlib.h>

#include "tests.h"

void ft_list_push_front(t_list **begin_list, void *data);
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));
int ft_list_size(t_list *first);

int test_empty() {
	t_list *head = NULL;

	ft_list_remove_if(&head, "HI", strcmp, (void (*)(void *))free);
	if (ft_list_size(head) != 0) {
		printf("ft_list_remove_if failed: expected 0, got %d\n", ft_list_size(head));
		return 1;
	}
	return 0;
}
