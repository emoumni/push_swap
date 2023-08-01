#include "push_swap_bonus.h"

void	twin_integers(t_struct **sa)
{
	t_struct	*current;
	t_struct	*temp;

	current = *sa;
    while (current)
	{
		temp = current->previous;
		while (temp)
		{
			if (current->data->content == temp->data->content)
				error_s();
			temp = temp->previous;
		}
		temp = current->next;
		while (temp)
		{
			if (current->data->content == temp->data->content)
				error_s();
			temp = temp->next;
		}
		current = current->next;
	}
}

void	memory_free(char **ptr, int j)
{
	while (j >= 0)
	{
		free(ptr[j]);
		j--;
	}
	free(ptr);
	return ;
}

void	length_checking(char *str)
{
	long		num;
	const char	*error_message;

	num = my_atol(str);
	error_message = "error\n";
	if (num > 2147483647  || num < (-2147483648) || strlen(str) > 11)
	{
		write (2, error_message, 6);
		exit(EXIT_FAILURE);
	}
}

void	errors_handler(int argc, char **argv, t_struct **sa)
{
	int			i;
	int			j;
	char		**len;
	t_struct	*tmp;

	i = 0;
	while (argv[++i])
		analyse_the_args(argv[i]);
	i = 0;
	while (++i < argc)
	{
		j = -1;
		len = ft_split(argv[i], ' ');
		while (len[++j])
		{
			length_checking(len[j]);
			tmp = ft_new_node(ft_atoi(len[j]));
			ft_lstadd_back_d(sa, tmp, 1);
		}
		memory_free(len, j);
	}
    twin_integers(sa);
}
