/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburlama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 06:01:53 by jburlama          #+#    #+#             */
/*   Updated: 2024/01/16 18:09:39 by jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	updates the index for each node from stack
	and sets the above median to true if is on the top half
	and to false if is on the bottom half
*/
void	update_index(t_stack *head)
{
	int	len;
	int	index;

	len = stack_len(head);
	index = 0;
	while (head)
	{
		head->index = index;
		if (index <= len / 2)
			head->is_above_median = true;
		else
			head->is_above_median = false;
		index++;
		head = head->next;
	}
}

/*
	iterates over stack a and finds the closest smaller	number from
	stack b
		if cant find a smaller number the target is the biggest number
	from stack b
*/
void	update_stack_a_target(t_stack *stack_a, t_stack *stack_b)
{
	long	target_number;
	t_stack	*target_node;
	t_stack	*current_node_b;

	while (stack_a)
	{
		target_number = LONG_MIN;
		current_node_b = stack_b;
		while (current_node_b)
		{
			if (current_node_b->number < stack_a->number
				&& current_node_b->number > target_number)
			{
				target_number = current_node_b->number;
				target_node = current_node_b;
			}
			current_node_b = current_node_b->next;
		}
		if (target_number == LONG_MIN)
			stack_a->target = get_max_value_node(stack_b);
		else
			stack_a->target = target_node;
		stack_a = stack_a->next;
	}
}

/*
	iterates over stack a and calculates all the possible cenarios to bring
	the a node and it's target node to the top, then assing the cost to the
	smallest value
*/
void	update_stack_a_cost(t_stack *a, t_stack *b)
{
	t_stack	*ptr_a;
	int		rr;
	int		rrr;
	int		ra_rrb;
	int		rra_rb;

	ptr_a = a;
	while (a)
	{
		rr = rr_p(a->index, a->target->index);
		rrr = rrr_p(a->index, stack_len(ptr_a), a->target->index, stack_len(b));
		ra_rrb = ra_rrb_p(a->index, a->target->index, stack_len(b));
		rra_rb = rra_rb_p(a->index, stack_len(ptr_a), a->target->index);
		if (rr < rrr)
			a->cost = rr;
		else
			a->cost = rrr;
		if (ra_rrb < a->cost)
			a->cost = ra_rrb;
		if (rra_rb < a->cost)
			a->cost = rra_rb;
		a = a->next;
	}
}

/*
	set the cheapest node to true
*/
void	update_cheapest(t_stack *head)
{
	long	cheapest_cost;
	t_stack	*target;

	cheapest_cost = LONG_MAX;
	while (head)
	{
		if (head->cost < cheapest_cost)
		{
			cheapest_cost = head->cost;
			target = head;
		}
		head = head->next;
	}
	target->is_cheapest = true;
}

/*
	iterates over stack b and finds the closest biggest	number from
	stack a
		if cant find a biguer number the target is the smallest number
	from stack a
*/
void	update_stack_b_target(t_stack *stack_a, t_stack *stack_b)
{
	long	target_number;
	t_stack	*target_node;
	t_stack	*current_node_a;

	while (stack_b)
	{
		target_number = LONG_MAX;
		current_node_a = stack_a;
		while (current_node_a)
		{
			if (current_node_a->number > stack_b->number
				&& current_node_a->number < target_number)
			{
				target_number = current_node_a->number;
				target_node = current_node_a;
			}
			current_node_a = current_node_a->next;
		}
		if (target_number == LONG_MAX)
			stack_b->target = get_min_value_node(stack_a);
		else
			stack_b->target = target_node;
		stack_b = stack_b->next;
	}
}
