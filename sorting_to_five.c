#include "push_swap.h"

void sort_five_nb(t_struct **sa, t_struct **sb)
{
    int size = list_size(*sa);
    *sb = NULL;

    if (size < 2)
    {
        exit(1);
    }

    while (size > 1 && size <= 5)
    {
        if (size == 2)
        {
            sort_two(sa);
        }
        else if (size == 3)
        {
            sort_three(sa);
        }
        else if (size == 4)
        {
            sort_four(sa, sb);
        }
        else if (size == 5)
        {
            sort_five(sa, sb);
        }
        break;
    }
}



void sort_two(t_struct **sa)
{
	t_struct *first;
	t_struct *second;

	first = *sa;
	second = (*sa)->next;
	if (first && second && first->data->content > second->data->content)
		do_swap_a(sa);
}

void sort_three(t_struct **sa)
{
	if ((*sa)->data->content > (*sa)->next->data->content
		&& (*sa)->data->content > (*sa)->next->next->data->content)
	{
		do_rotate_a(sa);
		if ((*sa)->data->content > (*sa)->next->data->content)
			do_swap_a(sa);
	}
	else if ((*sa)->data->content < (*sa)->next->data->content
		&& (*sa)->data->content < (*sa)->next->next->data->content)
	{
		if (args_check_issorted(sa))
		{
			do_swap_a(sa);
			do_rotate_a(sa);
		}
	}
	if ((*sa)->data->content < (*sa)->next->data->content
		&& (*sa)->data->content > (*sa)->next->next->data->content)
		do_reverse_rotate_a(sa);
	else if ((*sa)->data->content > (*sa)->next->data->content
		&& (*sa)->data->content < (*sa)->next->next->data->content)
		do_swap_a(sa);
}

void	sort_four(t_struct **sa, t_struct **sb)
{
	t_struct	*smallest;
	int			position;

	smallest = the_litlle_node(sa);
	position = position_no(smallest, sa);
	if (position > 2)
			smallest->data->movement_b = position - 4;
	else if (position <= 2)
		smallest->data->movement_b = position;
	while (smallest->data->movement_b > 0)
	{
		do_rotate_a(sa);
		smallest->data->movement_b--;
	}
	while (smallest->data->movement_b < 0)
	{
		do_reverse_rotate_a(sa);
		smallest->data->movement_b++;
	}
	push_to_stack_b(sa, sb);
	sort_three(sa);
	push_to_stack_a(sb, sa);
}

void sort_five(t_struct **sa, t_struct **sb)
{
    t_struct *smallest;
    int position;
    int mb;

    smallest = the_litlle_node(sa);
    position = position_no(smallest, sa);

    if (position > 2)
        mb = position - 5;
    else
        mb = position;

    while (mb > 0)
    {
        do_reverse_rotate_a(sa);
        mb--;
    }

    while (mb < 0)
    {
        do_reverse_rotate_a(sa);
        mb++;
    }

    smallest->data->movement_b = mb;

    push_to_stack_b(sa, sb);
    sort_four(sa, sb);
    push_to_stack_a(sb, sa);
}

