/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburlama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 20:00:38 by jburlama          #+#    #+#             */
/*   Updated: 2024/01/21 17:15:25 by jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				number;
	int				index;
	int				cost;
	bool			is_cheapest;
	bool			is_above_median;
	struct s_stack	*target;
	struct s_stack	*next;
}	t_stack;

void	print_error(void);
// stack inicialization | stack.c
void	stack_init(t_stack **stack_a, char **argv, bool is_heep);
t_stack	*stack_add_last(t_stack **stack_a, int n);
// check for erros
void	check_is_num(char **argv, bool is_heep);
bool	check_duplicates(t_stack *head);

// free.c
void	free_argv(char **argv);
void	free_all(t_stack **stack_a, char **argv, bool is_heep);
void	free_stack(t_stack **stack_a);

//operation
void	push(t_stack **dest, t_stack **src, char *operation);
void	swap(t_stack **head, char *operation);
void	ss(t_stack **stack_a, t_stack **stack_b, char *operation);
void	rotate(t_stack **head, char *operation);
void	rr(t_stack **stack_a, t_stack **stack_b, char *operation);
void	reverse_rotate(t_stack **head, char *operation);
void	rrr(t_stack **stack_a, t_stack **stack_b, char *operation);

// push_swap_utils
long	ft_atol(char *str);
bool	is_sorted(t_stack *head);
int		stack_len(t_stack *head);
t_stack	*get_max_value_node(t_stack *head);
t_stack	*get_min_value_node(t_stack *head);
void	update_cheapest(t_stack *head);

// push_swap_utils2
void	update_index(t_stack *head);
void	update_stack_a_target(t_stack *stack_a, t_stack *stack_b);
void	update_stack_a_cost(t_stack *stack_a, t_stack *stack_b);
void	update_stack_b_target(t_stack *stack_a, t_stack *stack_b);
void	bring_maxb_to_top(t_stack **stack_b);

//push_swap
void	sort_three(t_stack **head);
void	push_swap(t_stack **stack_a, t_stack **stack_b);
void	update_stack_a_info(t_stack	**stack_a, t_stack **stack_b);
void	push_a_to_b(t_stack **a, t_stack **b);
void	update_stack_b_info(t_stack **stack_a, t_stack **stack_b);

//push_swap2
void	push_b_to_a(t_stack **stack_a, t_stack **stack_b);
void	final_rotate(t_stack **stack_a);

//loop.c
void	dobble_rotate(t_stack **stack_a, t_stack **stack_b, t_stack *ptr);
void	dobble_rev_rotate(t_stack **stack_a, t_stack **stack_b, t_stack *ptr);
void	loop_rotate(t_stack **head, t_stack *ptr, char *operation);
void	loop_reverse_rotate(t_stack **head, t_stack *ptr, char *operation);

//cost.c
int		rr_p(int a_index, int b_index);
int		rrr_p(int a_index, int a_len, int b_index, int b_len);
int		ra_rrb_p(int a_index, int b_index, int b_len);
int		rra_rb_p(int a_index, int a_len, int b_index);

#endif
