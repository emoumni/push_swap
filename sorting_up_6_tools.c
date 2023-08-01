#include "push_swap.h"

void set_mb_value(t_struct *node, int position, int size)
{
    if (position > (size / 2))
    {
        node->data->mb = position - size;
    }
    else
    {
        node->data->mb = position;
    }
}

void move_largest_nodes_from_sb_to_sa(t_struct **sa, t_struct **sb)
{
    t_struct *largest;
    int size;
    int position;

    size = list_size(*sb);
    while (size)
    {
        largest = largest_node(sb);
        position = node_position(largest, sb);

        set_mb_value(largest, position, size);

        push_to_s(sa, sb, largest);
        size--;
    }
}

void push_to_s(t_struct **sa, t_struct **sb, t_struct *largest)
{
    int mb = largest->data->mb;

    if (mb > 0)
    {
        while (mb > 0)
        {
            do_rotate_b(sb);
            mb--;
        }
    }
    else if (mb < 0)
    {
        while (mb < 0)
        {
            do_reverse_rotate_b(sb);
            mb++;
        }
    }

    push_to_stack_a(sb, sa);
}

t_struct	*minimum_value_in_list(t_struct **sa)
{
    t_struct	*curr;
	t_struct	*minimum;
	
	if (!*sa)
        return NULL;
    curr = *sa;
    minimum = NULL;
	while (curr->next != *sa)
	{
		if (curr->data->value == -2 && (minimum == NULL
			|| curr->data->content < minimum->data->content))
			minimum = curr;
		curr = curr->next;
	}
	// Check the last element outside the loop (since the loop condition checks current->next).
	if (curr->data->value == -2 && (minimum == NULL
		|| curr->data->content < minimum->data->content))
		minimum = curr;
	return (minimum);
}
