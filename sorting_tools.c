/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoumni <emoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 00:34:39 by emoumni           #+#    #+#             */
/*   Updated: 2023/08/02 00:47:59 by emoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_struct	*the_litlle_node(t_struct **head)
{
	t_struct	*curr;
	t_struct	*litlle;

	if (*head == NULL)
		return (NULL);
	curr = (*head)->next;
	litlle = *head;
	while (curr != *head)
	{
		if (curr->data->content < litlle->data->content)
			litlle = curr;
		curr = curr->next;
	}
	return (litlle);
}

int	position_no(t_struct *current, t_struct **stack)
{
	int			position;
	t_struct	*look;

	look = *stack;
	position = 0;
	while (look && look != current)
	{
		position++;
		look = look->next;
	}
	if (!look)
		return (-1);
	return (position);
}

t_struct	*the_bigger_node(t_struct **sb)
{
	t_struct	*curr;
	t_struct	*bigger;

	if (*sb == NULL)
		return (NULL);
	curr = *sb;
	bigger = *sb;
	curr = curr->next;
	while (curr != *sb)
	{
		if (curr->data->value > bigger->data->value)
			bigger = curr;
		curr = curr->next;
	}
	return (bigger);
}
