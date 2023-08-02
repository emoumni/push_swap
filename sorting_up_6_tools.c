#include "push_swap.h"

void    set_mb_value(t_struct *node, int position, int size)
{
    if (position > (size / 2))
    {
        node->data->movement_b = position - size;
    }
    else
    {
        node->data->movement_b = position;
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
        largest = the_bigger_node(sb);
        position = position_no(largest, sb);

        set_mb_value(largest, position, size);

        push_to_s(sa, sb, largest);
        size--;
    }
}

void push_to_s(t_struct **sa, t_struct **sb, t_struct *largest)
{
    int mb = largest->data->movement_b;

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
	if (curr->data->value == -2 && (minimum == NULL
		|| curr->data->content < minimum->data->content))
		minimum = curr;
	return (minimum);
}
