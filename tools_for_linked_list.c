/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_for_linked_list.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoumni <emoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 00:35:10 by emoumni           #+#    #+#             */
/*   Updated: 2023/08/02 00:53:37 by emoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_struct	*ft_new_node(int content)
{
	t_struct	*node1;

	node1 = (t_struct *)malloc(sizeof(t_struct));
	if (!node1)
		return (NULL);
	node1->data = (t_data *)malloc(sizeof(t_data));
	if (!node1->data)
	{
		free(node1);
		return (NULL);
	}
	node1->data->content = content;
	node1->data->value = -2;
	node1->next = NULL;
	node1->previous = NULL;
	return (node1);
}

t_struct	*ft_last_node(t_struct *lst)
{
	t_struct	*current;

	current = lst;
	if (current)
	{
		while (current->next)
		{
			current = current->next;
		}
	}
	return (current);
}

void	ft_lstadd_back_d(t_struct **lst, t_struct *new, int v)
{
	t_struct	*lnode;

	if (v == 0)
	{
		if (*lst)
		{
			lnode = ft_last_node(*lst);
			lnode->next = *lst;
			(*lst)->previous = lnode;
		}
	}
	else
	{
		if (new)
		{
			if (*lst)
			{
				lnode = ft_last_node(*lst);
				lnode->next = new;
				new->previous = lnode;
			}
			else
				*lst = new;
		}
	}
}

int	list_size(t_struct *head)
{
	int			count;
	t_struct	*current;

	current = head;
	count = 0;
	while (current != NULL)
	{
		count++;
		current = current->next;
		if (current == head)
			break ;
	}
	return (count);
}
