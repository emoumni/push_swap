#include "push_swap_bonus.h"

int	stack_length(t_struct **sa, int size)
{
	int			n_size;

	n_size = list_size(*sa);
	if (n_size != size)
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_struct	*sa;
	t_struct	*sb;
	char		*line;
	int			size; 

	sa = NULL;
	sb = NULL;
	line = NULL;
	errors_handler(argc, argv, &sa);
	ft_lstadd_back_d(&sa, NULL, 0);
	size = list_size(sa);
	if (size == 0)
		exit(0);
	while (get_next_line(0, &line))
	{
		checking_moves(&sa, &sb, line);
		free(line);
	}
	if (check_stack(&sa))
	{		
		write(2, "KO\n", 3);
		exit(1);
	}
	if (stack_length(&sa, size))
	{		
		write(2, "KO\n", 3);
		exit(1);
	}
	else
		write (2, "OK\n", 3);
	return (0);
}