/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoumni <emoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 00:34:08 by emoumni           #+#    #+#             */
/*   Updated: 2023/08/02 20:42:16 by emoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	args_check_issorted(t_struct **sa)
{
	t_struct	*current;

	if (!(*sa))
		return (0);
	current = *sa;
	while (current->next != *sa)
	{
		if (current->data->content > current->next->data->content)
			return (1);
		current = current->next;
	}
	return (0);
}

t_struct	*initialize(int ac, char **av, int *size)
{
	t_struct	*sa;

	sa = NULL;
	errors_handler(ac, av, &sa);
	ft_lstadd_back_d(&sa, NULL, 0);
	*size = list_size(sa);
	return (sa);
}

void	handlesorting(int *size, t_struct **sa, t_struct **sb, int *v)
{
	if (*size <= 5)
		sort_five_nb(sa, sb);
	else
	{
		if (*size >= 500)
			*v = 1;
		sorting(sa, sb, *v);
		move_largest_nodes_from_sb_to_sa(sa, sb);
	}
}

void func(void)
{
	system("leaks push_swap");
}

int	main(int ac, char **av)
{
	atexit(func);
	t_struct	*sa;
	t_struct	*sb;
	int			v;
	int			size;

	sa = initialize(ac, av, &size);
	if (args_check_issorted(&sa))
		handlesorting(&size, &sa, &sb, &v);
	if (!args_check_issorted(&sa))
		exit(1);
	return (0);
}
