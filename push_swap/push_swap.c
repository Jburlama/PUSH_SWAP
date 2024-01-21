/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburlama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 05:36:56 by jburlama          #+#    #+#             */
/*   Updated: 2024/01/21 17:49:47 by jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	sort stack with three nodes
	finds the node with the hiest value and rotates to the bottom
	if is not sorted swap
*/
void	sort_three(t_stack **head)
{
	t_stack	*max_value_node;

	max_value_node = get_max_value_node(*head);
	if (*head == max_value_node)
		rotate(head, "ra");
	else if ((*head)->next == max_value_node)
		reverse_rotate(head, "rra");
	if (!is_sorted(*head))
		swap(head, "sa");
}

/*
	push to b while a is bigger then 3 or is sorted
		when b has at least 2 nodes, find the taget to each node 
		from a to b then push the cheapest
	sort 3 from stack a
		push b nodes to to specific targets on stack a
	ra or rra stack be till the smallest is on top
*/
void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_len(*stack_a) > 3 && !is_sorted(*stack_a))
		push(stack_b, stack_a, "pb");
	if (stack_len(*stack_a) > 3 && !is_sorted(*stack_a))
		push(stack_b, stack_a, "pb");
	while (stack_len(*stack_a) > 3 && !is_sorted(*stack_a))
	{
		update_stack_a_info(stack_a, stack_b);
		push_a_to_b(stack_a, stack_b);
	}
	if (stack_len(*stack_a) == 3)
		sort_three(stack_a);
	update_index(*stack_a);
	bring_maxb_to_top(stack_b);
	update_index(*stack_a);
	while (*stack_b)
	{
		update_stack_b_info(stack_a, stack_b);
		push_b_to_a(stack_a, stack_b);
	}
	final_rotate(stack_a);
}

/*
	updates the stack info
		sets the index
		finds the targets
		update the cost
		finds the cheapest
*/
void	update_stack_a_info(t_stack	**stack_a, t_stack **stack_b)
{
	update_index(*stack_a);
	update_index(*stack_b);
	update_stack_a_target(*stack_a, *stack_b);
	update_stack_a_cost(*stack_a, *stack_b);
	update_cheapest(*stack_a);
}

/*
	calculate all the possible cenarios and do the chepest operations to
	bring the cheapest node to the top and it's target node to top 
	then pushes to b
*/
void	push_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*ptr;
	int		op[4];

	ptr = *a;
	while (!ptr->is_cheapest)
		ptr = ptr->next;
	op[0] = rr_p(ptr->index, ptr->target->index);
	op[1] = rrr_p(ptr->index, stack_len(*a), ptr->target->index, stack_len(*b));
	op[2] = ra_rrb_p(ptr->index, ptr->target->index, stack_len(*b));
	op[3] = rra_rb_p(ptr->index, stack_len(*a), ptr->target->index);
	if (ptr->cost == op[0])
		dobble_rotate(a, b, ptr);
	else if (ptr->cost == op[1])
		dobble_rev_rotate(a, b, ptr);
	else if (ptr->cost == op[2])
	{
		loop_rotate(a, ptr, "ra");
		loop_reverse_rotate(b, ptr->target, "rrb");
	}
	else if (ptr->cost == op[3])
	{
		loop_reverse_rotate(a, ptr, "rra");
		loop_rotate(b, ptr->target, "rb");
	}
	push(b, a, "pb");
}

/*
	updates the stack b info to to back to stack a
		index | is above or bellow median
		the target node
*/
void	update_stack_b_info(t_stack **stack_a, t_stack **stack_b)
{
	update_index(*stack_a);
	update_index(*stack_b);
	update_stack_b_target(*stack_a, *stack_b);
}
