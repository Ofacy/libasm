#ifndef TESTS_H
# define TESTS_H

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}	t_list;

int test_basic();
int test_empty();
int test_scrambled();

#endif