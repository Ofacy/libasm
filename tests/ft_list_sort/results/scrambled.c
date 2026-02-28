#include "stdio.h"
#include "string.h"
#include "unistd.h"
#include <errno.h>
#include <stdlib.h>

#include "tests.h"

void ft_list_push_front(t_list **begin_list, void *data);
void ft_list_sort(t_list **begin_list, int (*cmp)());
int ft_list_size(t_list *first);

int int_subtract(int *first, int *second);

void cft_list_sort(t_list **head, int (*cmp)(void *, void *)) {
	t_list **first;
	t_list **second;

	first = head;
	second = &(*head)->next;
	while (*first) {
		if (cmp((*first)->data, (*second)->data) > 0) {
			void *temp_data = (*first)->data;
			(*first)->data = (*second)->data;
			(*second)->data = temp_data;
		}
		second = &(*second)->next;
		if (*second != 0)
			continue;
		first = &(*first)->next;
		second = &(*first)->next;
		if (!*second) {
			break;
		}
	}
}

int test_scrambled() {
	t_list *head = NULL;
	int numbers[] = {3, 5, 0, 2, 8, 1, 4, 9, 6, 7};
	const int numbers_count = sizeof(numbers) / sizeof(numbers[0]);

	for (int i = 0; i < numbers_count; i++) {
		int* number = malloc(sizeof(int));
		if (!number)
			return 1;//??
		*number = numbers[i];
		ft_list_push_front(&head, number);
	}
	ft_list_sort(&head, (int (*)())int_subtract);
	if (ft_list_size(head) != numbers_count)
		return 1;
	for (int i = 0; i < numbers_count; i++) {
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
