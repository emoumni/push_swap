#include "push_swap.h"

void	do_reverse_rotate_a(t_struct **stack_a)
{
	if (*stack_a && (*stack_a)->previous) // Check if sa and the previous node exist in one condition
	{
		*stack_a = (*stack_a)->previous;
		write(1, "rra\n", 4);
	}
}

void	do_reverse_rotate_b(t_struct **stack_b)
{
	if (*stack_b && (*stack_b)->previous) // Check if sa and the previous node exist in one condition
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
