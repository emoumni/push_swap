#include "push_swap_bonus.h"

void	checking_moves(t_struct **sa, t_struct **sb, char *line)
{
	if (!ft_strcmp(line, "pb\n"))
		push_to_stack_b(sa, sb);
	else if (!ft_strcmp(line, "pa\n"))
		push_to_stack_a(sb, sa);
	else if (!ft_strcmp(line, "sa\n"))
		do_swap_a(sa);
	else if (!ft_strcmp(line, "sb\n"))
		do_swap_b(sb);
	else if (!ft_strcmp(line, "ss\n"))
		do_swap_a_b(sa, sb);
	else if (!ft_strcmp(line, "ra\n"))
		do_rotate_a(sa);
	else if (!ft_strcmp(line, "rb\n"))
		do_reverse_rotate_b(sb);
	else if (!ft_strcmp(line, "rr\n"))
		do_rotate_both_a_b(sa, sb);
	else if (!ft_strcmp(line, "rra\n"))
		do_reverse_rotate_a(sa);
	else if (!ft_strcmp(line, "rrb\n"))
		do_reverse_rotate_b(sb);
	else if (!ft_strcmp(line, "rrr\n"))
		do_reverse_rotate_a_b(sa, sb);
	else
		error_s();
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1)
		return (0);
	if (!s2)
		return ((char *)s1);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
