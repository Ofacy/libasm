
typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}	t_list;

// written in C as an example

void cft_list_sort(t_list **head, int (*cmp)(void *, void *)) {
	t_list **first;
	t_list **second;

	first = head;
	second = &(*head)->next;
	while (*first) {
		t_list *first_node = *first;
		t_list *second_node = *second;
		if (cmp(first_node->data, second_node->data) > 0) {
			void *temp_data = first_node->data;
			first_node->data = second_node->data;
			second_node->data = temp_data;
		}
		second = &(second_node->next);
		if (*second != 0)
			continue;
		first = &(first_node->next);
		second = &(*first)->next;
		if (!*second) {
			break;
		}
	}
}