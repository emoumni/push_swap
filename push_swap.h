/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoumni <emoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 00:34:19 by emoumni           #+#    #+#             */
/*   Updated: 2023/08/02 20:00:52 by emoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>	
# include <string.h>	
# include <stddef.h>

typedef struct s_data
{
	int	content;
	int	value;
	int	movement_b;
}	t_data;

typedef struct s_list
{
	struct s_list	*previous;
	struct s_data	*data;
	struct s_list	*next;
}	t_struct;

//parsing

void		analyse_the_args(char *str);
void		error_s(void);
int			ft_isdigit(int c);
void		string_check(char *str, long i, long trigger);
void		errors_handler(int argc, char **argv, t_struct **sa);
void		length_checking(char *str);
void		memory_free(char **ptr, int j);
void		twin_integers(t_struct **sa);
size_t		ft_strlen(const char *s);
int			ft_isspace(int c);
long		my_atol(const char *str);
int			ft_atoi(const char *str);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strdup(const char *s1);
char		**ft_split(char const *s, char c);
int			args_check_issorted(t_struct **sa);

//Linked list tools

t_struct	*ft_new_node(int content);
t_struct	*ft_last_node(t_struct *lst);
void		ft_lstadd_back_d(t_struct **lst, t_struct *new, int v);
int			list_size(t_struct *head);

//moves

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

// sorting five numbers

t_struct	*the_litlle_node(t_struct **head);
int			position_no(t_struct *current, t_struct **stack);
t_struct	*the_bigger_node(t_struct **sb);
void		sort_five_nb(t_struct **sa, t_struct **sb);
void		sort_two(t_struct **sa);
void		sort_three(t_struct **sa);
void		sort_four(t_struct **sa, t_struct **sb);
void		sort_five(t_struct **sa, t_struct **sb);

//sorting 6 up

t_struct	*the_bigger_node(t_struct **sb);
void		move_largest_nodes_from_sb_to_sa(t_struct **sa, t_struct **sb);
void		move_node_to_stack_b(t_struct **sa, t_struct **sb, int v, int z);
t_struct	*minimum_value_in_list(t_struct **sa);
void		sorting(t_struct **sa, t_struct **sb, int v);
void		push_to_s(t_struct **sa, t_struct **sb, t_struct *largest);
t_struct	*initialize(int ac, char **av, int *size);
void		handlesorting(int *size, t_struct **sa, t_struct **sb, int *v);
void		do_actions_according_to_mb(t_struct **sb, t_struct *largest);
void		set_mb_value(t_struct *node, int position, int size);
void		push_nodes_to_sb(t_struct **sa, t_struct **sb, int *z, int t);
int			calculate_t_value(int v);

#endif