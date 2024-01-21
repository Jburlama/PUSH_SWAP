/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburlama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 08:11:15 by jburlama          #+#    #+#             */
/*   Updated: 2024/01/21 17:49:19 by jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	rotate the target node from b and rotate or reverse rotate
	wheter is above or bellow median, then pushes to a
*/
void	push_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_b)->target->is_above_median)
	{
		loop_rotate(stack_a, (*stack_b)->target, "ra");
		push(stack_a, stack_b, "pa");
	}
	else
	{
		loop_reverse_rotate(stack_a, (*stack_b)->target, "rra");
		push(stack_a, stack_b, "pa");
	}
}

/*
	find the smallest node from the stack and bring's it to the top
*/
void	final_rotate(t_stack **stack_a)
{
	t_stack	*min;

	update_index(*stack_a);
	min = get_min_value_node(*stack_a);
	while (min->index != 0)
	{
		if (min->is_above_median)
			rotate(stack_a, "ra");
		else
			reverse_rotate(stack_a, "rra");
		update_index(*stack_a);
	}
}

void	bring_maxb_to_top(t_stack **stack_b)
{
	t_stack	*max_node;

	update_index(*stack_b);
	max_node = get_max_value_node(*stack_b);
	while (max_node->index != 0)
	{
		if (max_node->is_above_median)
			loop_rotate(stack_b, max_node, "rb");
		else
			loop_reverse_rotate(stack_b, max_node, "rrb");
	}
}
