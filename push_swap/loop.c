/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburlama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 07:21:37 by jburlama          #+#    #+#             */
/*   Updated: 2024/01/15 19:45:12 by jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	rotate t_stack a and b untill the cheapest node or the
	or the target node is on top
*/
void	dobble_rotate(t_stack **stack_a, t_stack **stack_b, t_stack *ptr)
{
	while (ptr->index != 0 && ptr->target->index != 0)
	{
		rr(stack_a, stack_b, "rr");
		update_index(*stack_a);
		update_index(*stack_b);
	}
	loop_rotate(stack_a, ptr, "ra");
	loop_rotate(stack_b, ptr->target, "rb");
}

/*
	reverse rotate t_stack a and b untill the cheapest node or the
	or the target node is on top
*/
void	dobble_rev_rotate(t_stack **stack_a, t_stack **stack_b, t_stack *ptr)
{
	while (ptr->index != 0 && ptr->target->index != 0)
	{
		rrr(stack_a, stack_b, "rrr");
		update_index(*stack_a);
		update_index(*stack_b);
	}
	loop_reverse_rotate(stack_a, ptr, "rra");
	loop_reverse_rotate(stack_b, ptr->target, "rrb");
}

// rotate the node until the node pointed by ptr is on top
void	loop_rotate(t_stack **head, t_stack *ptr, char *operation)
{
	while (ptr->index != 0)
	{
		rotate(head, operation);
		update_index(*head);
	}
}

// reverse rotate the node until the node pointed by ptr is on top
void	loop_reverse_rotate(t_stack **head, t_stack *ptr, char *operation)
{
	while (ptr->index != 0)
	{
		reverse_rotate(head, operation);
		update_index(*head);
	}
}
