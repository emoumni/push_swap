#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_data
{
	int content;
	int value;
	int movement_b;
} t_data;

typedef struct s_list
{
	struct s_list *previous;
	struct s_data *data;
	struct s_list *next;
} t_struct;


#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10000
#endif

#ifndef FD_MAX
# define FD_MAX 1000
#endif

char	*ft_strjoin(char const *s1, char const *s2);
void	checking_moves(t_struct **sa, t_struct **sb, char *line);
int	ft_strcmp(char *s1, char *s2);
void	analyse_the_args(char *str);
void	error_s(void);
int	ft_isdigit(int c);
void	string_check(char *str, long i, long trigger);
void errors_handler(int argc, char **argv, t_struct **sa);
void	length_checking(char *str);
void	memory_free(char **ptr, int j);
void twin_integers(t_struct **sa);
size_t	ft_strlen(const char *s);
int	ft_isspace(int c);
long	my_atol(const char *str);
int	ft_atoi(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
char	**ft_split(char const *s, char c);
int args_check_issorted(t_struct **sa);
t_struct *ft_new_node(int content);
t_struct	*ft_last_node(t_struct *lst);
void	ft_lstadd_back_d(t_struct **lst, t_struct *new, int v);
int list_size(t_struct *head);
void		do_reverse_rotate_a(t_struct **stack_a);
void		do_reverse_rotate_b(t_struct **stack_b);
void		do_reverse_rotate_a_b(t_struct **stack_a, t_struct **stack_b);
void		do_rotate_a(t_struct **stack_a);
void		do_rotate_b(t_struct **stack_b);
void		do_rotate_both_a_b(t_struct **stack_a, t_struct **stack_b);
void		do_swap_a(t_struct **head);
void		do_swap_b(t_struct **head);
void		do_swap_a_b(t_struct **a, t_struct **b);
void		push_to_stack_a(t_struct **stack_1, t_struct **stack_2);
void		push_to_stack_b(t_struct **stack_1, t_struct **stack_2);
void		check_the_stack(t_struct **stack);
int get_next_line(int fd, char **line);
int check_stack(t_struct **sa);
int	stack_length(t_struct **sa, int size);

#endif
