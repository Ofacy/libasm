#include "stdio.h"
#include "string.h"
#include "unistd.h"
#include <errno.h>
#include <stdlib.h>

#include "tests.h"

void ft_list_push_front(t_list **begin_list, void *data);
void ft_list_sort(t_list **begin_list, int (*cmp)());
int ft_list_size(t_list *first);

int int_subtract(int *first, int *second) {
	int result = *first - *second;
	return result;
}

int test_basic() {
	t_list *head = NULL;

	for (int i = 0; i < 4; i++) {
		int* number = malloc(sizeof(int));
		if (!number)
			return 1;//??
		*number = i;
		ft_list_push_front(&head, number);
	}
	ft_list_sort(&head, (int (*)())int_subtract);
	if (ft_list_size(head) != 4)
		return 1;
	for (int i = 0; i < 4; i++) {
		int data = *(int *) head->data;
		if (data != i)
			return 1;
		t_list *next = head->next;
		free(head->data);
		free(head);
		head = next;
	}
	return 0;
}
