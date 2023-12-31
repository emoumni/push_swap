#include "push_swap_bonus.h"

void do_swap_a(t_struct **head)
{
	int tmporary;

	if (*head && (*head)->next) // Check if head and next node exist in one condition
	{
		tmporary = (*head)->data->content;
		(*head)->data->content = (*head)->next->data->content;
		(*head)->next->data->content = tmporary;
	}
}

void	do_swap_b(t_struct **head)
{
	int	tmporary;

	if (*head && (*head)->next)// Check if head and next node exist in one condition
	{
		tmporary = (*head)->data->content;
		(*head)->data->content = (*head)->next->data->content;
		(*head)->next->data->content = tmporary;
	}
}

void	do_swap_a_b(t_struct **a, t_struct **b)
{
	do_swap_a(a);
	do_swap_b(b);
}