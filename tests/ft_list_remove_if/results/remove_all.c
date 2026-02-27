#include "stdio.h"
#include "string.h"
#include "unistd.h"
#include <errno.h>
#include <stdlib.h>

#include "tests.h"

void ft_list_push_front(t_list **begin_list, void *data);
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));
int ft_list_size(t_list *first);

int is_int_equal(void *data, void *data_src) {
	return *((int *)data) == *((int *)data_src);
}

int test_remove_all() {
	t_list *head = NULL;

	for (int i = 0; i < 100; i++) {
		int* number = malloc(sizeof(int));
		if (!number)
			return 1;//??
		*number = 0;
		ft_list_push_front(&head, number);
	}
	ft_list_remove_if(&head, "HI", is_int_equal, (void (*)(void *))free);
	if (head != NULL)
		return 1;
	return 0;
}
