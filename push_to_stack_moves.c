#include "push_swap.h"

void	push_to_stack_a(t_struct **stack_1, t_struct **stack_2)
{
	t_struct *temp;

	write(1, "pa\n", 3);
    if (!*stack_1)
		return;
	temp = *stack_1;
	check_the_stack(stack_1);
	if (!*stack_2)
	{
		*stack_2 = temp;
		(*stack_2)->next = (*stack_2);
		(*stack_2)->previous = (*stack_2);
	}
	else
	{
		temp->next = *stack_2;
		temp->previous = (*stack_2)->previous;
		(*stack_2)->previous->next = temp;
		(*stack_2)->previous = temp;
		*stack_2 = temp;
	}
}

void	push_to_stack_b(t_struct **stack_1, t_struct **stack_2)
{
	t_struct *temp;

	write(1, "pb\n", 3);
	if (!*stack_1)
		return;
	temp = *stack_1;
	check_the_stack(stack_1);
	if (!*stack_2)
	{
		*stack_2 = temp;
		(*stack_2)->next = (*stack_2);
		(*stack_2)->previous = (*stack_2);
	}
	else
	{
		temp->next = *stack_2;
		temp->previous = (*stack_2)->previous;
		(*stack_2)->previous->next = temp;
		(*stack_2)->previous = temp;
		*stack_2 = temp;
	}
}

void	check_the_stack(t_struct **stack)
{
	t_struct	*next_node;
	t_struct	*previous_node;

	if (!*stack || (*stack)->next == *stack)
	{
		*stack = NULL;
        return;
    }

    next_node = (*stack)->next;
    previous_node = (*stack)->previous;

    previous_node->next = next_node;
    next_node->previous = previous_node;

    *stack = next_node;
}
