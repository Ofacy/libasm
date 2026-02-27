#include "stdio.h"
#include "string.h"
#include "unistd.h"
#include <errno.h>
#include <stdlib.h>

#include "tests.h"

void ft_list_push_front(t_list **begin_list, void *data);
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));
int ft_list_size(t_list *first);

int is_int_mod_eq1(void *data, void *data_src) {
	return (*((int *)data) % *((int *)data_src)) == 1;
}

int is_int_equal(void *data, void *data_src);

int test_remove_even() {
	t_list *head = NULL;
	static int two = 2;

	for (int i = 0; i < 100; i++) {
		int* number = malloc(sizeof(int));
		if (!number)
			return 1;//??
		*number = i;
		ft_list_push_front(&head, number);
	}
	ft_list_remove_if(&head, &two, is_int_mod_eq1, (void (*)(void *))free);
	if (ft_list_size(head) != 50)
		return 1;
	for (int i = 49; i >= 0; i--) {
		int data = *(int *) head->data;
		if (data != i * 2 + 1)
			return 1;
		t_list *next = head->next;
		free(head->data);
		free(head);
		head = next;
	}
	return 0;
}
