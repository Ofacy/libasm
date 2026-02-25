/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liblibft_lst.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 03:18:40 by ibertran          #+#    #+#             */
/*   Updated: 2024/01/15 02:12:13 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBlibft_LST_H
# define LIBlibft_LST_H

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		libft_lstsize(t_list *lst);
t_list	*libft_lstlast(t_list *lst);
t_list	*libft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*libft_lstnew(void *content);
void	libft_lstadd_back(t_list **lst, t_list *new);
void	libft_lstadd_front(t_list **lst, t_list *new);
void	libft_lstclear(t_list **lst, void (*del)(void*));
void	libft_lstdelone(t_list *lst, void (*del)(void*));
void	libft_lstiter(t_list *lst, void (*f)(void *));

#endif