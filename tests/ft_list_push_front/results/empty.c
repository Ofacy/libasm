#include "stdio.h"
#include "string.h"
#include "unistd.h"
#include <errno.h>
#include <stdlib.h>

#include "tests.h"

void ft_list_push_front(t_list **begin_list, void *data);

int test_empty() {
	t_list *head = NULL;

	ft_list_push_front(&head, "first");
	if (head == NULL) {
		printf("ft_list_push_front failed: head is NULL\n");
		return 1;
	}
	if (head->next != NULL) {
		printf("ft_list_push_front failed: head->next is not NULL\n");
		return 1;
	}
	if (strcmp(head->data, "first") != 0) {
		printf("ft_list_push_front failed: expected head data 'first', got '%s'\n", (char *)head->data);
		return 1;
	}
	free(head);
	return 0;
}
