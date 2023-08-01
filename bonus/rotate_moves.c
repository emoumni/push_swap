#include "push_swap_bonus.h"

void	do_rotate_a(t_struct **stack_a)
{
	if (*stack_a && (*stack_a)->next) // Check if sa and the next node exist in one condition
		*stack_a = (*stack_a)->next;
}

void	do_rotate_b(t_struct **stack_b)
{
	if (*stack_b && (*stack_b)->next) // Check if sa and the next node exist in one condition
		*stack_b = (*stack_b)->next;
}

void	do_rotate_both_a_b(t_struct **stack_a, t_struct **stack_b)
{
	do_rotate_a(stack_a);
	do_rotate_b(stack_b);
}

void	error_s(void)
{
    const char	*error_message;

	error_message = "Error\n";
	write (2, error_message, 6);
	exit(1);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}