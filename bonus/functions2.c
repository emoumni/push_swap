#include "push_swap_bonus.h"

void	checking_moves(t_struct **sa, t_struct **sb, char *line)
{
	if (ft_strcmp(line, "pb\n"))
		push_to_stack_b(sa, sb);
	else if (ft_strcmp(line, "pa\n"))
		push_to_stack_a(sb, sa);
	else if (ft_strcmp(line, "sa\n"))
		do_swap_a(sa);
	else if (ft_strcmp(line, "sb\n"))
		do_swap_b(sb);
	else if (ft_strcmp(line, "ss\n"))
		do_swap_a_b(sa, sb);
	else if (ft_strcmp(line, "ra\n"))
		do_rotate_a(sa);
	else if (ft_strcmp(line, "rb\n"))
		do_rotate_b(sb);
	else if (ft_strcmp(line, "rr\n"))
		do_rotate_both_a_b(sa, sb);
	else if (ft_strcmp(line, "rra\n"))
		do_reverse_rotate_a(sa);
	else if (ft_strcmp(line, "rrb\n"))
		do_reverse_rotate_b(sb);
	else if (ft_strcmp(line, "rrr\n"))
		do_reverse_rotate_a_b(sa, sb);
	else
		write(2, "here", 4);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ret;
	size_t	i;
	size_t	j;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ret = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!ret)
		return (NULL);
	i = -1;
	j = -1;
	while (++i < s1_len)
		ret[i] = s1[i];
	while (++j < s2_len)
		ret[i++] = s2[j];
	ret[i] = '\0';
	return (ret);
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
