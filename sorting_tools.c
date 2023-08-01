#include "push_swap.h"

t_struct *smallest_node(t_struct **head)
{
	t_struct *current;
	t_struct *smallest;

	current = *head;
	smallest = *head;
	while (1)
	{
		if (current->data->content < smallest->data->content)
			smallest = current;
		current = current->next;
		if (current == *head)
			break;
	}
	return smallest;
}

int node_position(t_struct *current, t_struct **stack)
{
	t_struct *search;
	int i;

	i = -1;
	search = *stack;
	while (1)
	{
		i++;
		if (current->data->content == search->data->content)
			break;
		search = search->next;
	}
	return i;
}

t_struct *largest_node(t_struct **sb)
{
    t_struct *current;
    t_struct *largest;

    current = *sb;
    largest = *sb;
    while (1)
    {
        if (current->data->value > largest->data->value)
            largest = current;
        current = current->next;
        if (current == (*sb))
            break;
    }
    return (largest);
}
