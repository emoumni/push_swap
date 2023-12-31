/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_moves.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoumni <emoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 00:34:25 by emoumni           #+#    #+#             */
/*   Updated: 2023/08/02 00:41:41 by emoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_reverse_rotate_a(t_struct **stack_a)
{
	if (*stack_a && (*stack_a)->previous)
	{
		*stack_a = (*stack_a)->previous;
		write(1, "rra\n", 4);
	}
}

void	do_reverse_rotate_b(t_struct **stack_b)
{
	if (*stack_b && (*stack_b)->previous)
	{
		*stack_b = (*stack_b)->previous;
		write(1, "rrb\n", 4);
	}
}

void	do_reverse_rotate_a_b(t_struct **stack_a, t_struct **stack_b)
{
	do_reverse_rotate_a(stack_a);
	do_reverse_rotate_b(stack_b);
	write (1, "rrr\n", 4);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || 
		c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}
