#include "push_swap.h"

void	sorting(t_struct **sa, t_struct **sb, int v)
{
	t_struct	*head;
	int			i;
	int			size;
	int			z;

	*sb = NULL;
	z = 0;
	size = list_size(*sa);
	i = 0;
	head = minimum_value_in_list(sa);
	while (size != 0)
	{
		head->data->value = i++;
		head = minimum_value_in_list(sa);
		size--;
	}
	move_node_to_stack_b(sa, sb, v, z);
}

int	calculate_t_value(int v)
{
	int	t;

	if (v == 0)
		t = 16;
	if (v == 1)
		t = 30;
	return (t);
}

void	push_nodes_to_sb(t_struct **sa, t_struct **sb, int *z, int t)
{
    t_struct	*current;
	int		requiredValue;

	current = *sa;
	if (current->data->value <= *z)
	{
		push_to_stack_b(sa, sb);
		(*z)++;
	}
	else
	{
		requiredValue = *z + t;
		if (current->data->value < requiredValue)
		{
			push_to_stack_b(sa, sb);
			do_rotate_b(sb);
			(*z)++;
		}
		else
			do_rotate_a(sa);
    }
}

void	move_node_to_stack_b(t_struct **sa, t_struct **sb, int v, int z)
{
	int	t;

	t = calculate_t_value(v);
	while (*sa)
		push_nodes_to_sb(sa, sb, &z, t);
}

