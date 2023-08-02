#include "push_swap_bonus.h"

void	analyse_the_args(char *str)
{
	long	i;
	long	counter;

	i = 0;
	counter = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		counter++;
		i++;
	}
	if (str[i] == '\0')
        error_s();
	string_check(str, i - 1, counter);
}

void	string_check(char *str, long i, long trigger)
{
	long	j;

	i++;
	j = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '-' && str[i] != '+')
			error_s();
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i - 1] != ' ' && str[i - 1] != '\0')
				trigger = 3;
			if (!ft_isdigit(str[i + 1]))
                error_s();
		}
		if (ft_isdigit(str[i]))
			j++;
        if (str[i] == ' ' && str[i + 1] == '\0' && j == 0)
			error_s();
		if (trigger > 2)
			error_s();
		i++;
	}
}

int check_stack(t_struct **sa)
{
	t_struct *current;

	if (!(*sa))
		return (1);
	current = *sa;
	while (1)
	{
		if (current->data->content > current->next->data->content)
			return (1);
		current = current->next;
		if (current->next == *sa)
			break;
	}
	return (0);
}
