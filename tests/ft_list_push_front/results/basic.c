#include "stdio.h"
#include "string.h"
#include "unistd.h"
#include <errno.h>
#include <stdlib.h>

#include "tests.h"

void ft_list_push_front(t_list **begin_list, void *data);

int test_basic() {
	t_list *head = NULL;
	t_list first_node = { .data = "first", .next = NULL };

	head = &first_node;
	ft_list_push_front(&head, "second");
	if (head == NULL) {
		printf("ft_list_push_front failed: head is NULL\n");
		return 1;
	}
	if (head->next != &first_node) {
		printf("ft_list_push_front failed: head->next is not first_node\n");
		printf("Expected head->next to be %p, got %p\n", (void *)&first_node, (void *)head->next);
		return 1;
	}
	if (strcmp(head->data, "second") != 0) {
		printf("ft_list_push_front failed: expected head data 'second', got '%s'\n", (char *)head->data);
		return 1;
	}
	free(head);
	return 0;
}
