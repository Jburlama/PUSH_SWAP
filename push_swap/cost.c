/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburlama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 07:01:50 by jburlama          #+#    #+#             */
/*   Updated: 2024/01/20 21:12:45 by jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// return the cost of rotating both stacks
int	rr_p(int a_index, int b_index)
{
	int	rr_cost;

	if (a_index > b_index)
		rr_cost = a_index;
	else
		rr_cost = b_index;
	return (rr_cost);
}

// return the cost of reverse rotating both stacks
int	rrr_p(int a_index, int a_len, int b_index, int b_len)
{
	int	rrr_cost;

	if ((a_len - a_index) > (b_len - b_index))
		rrr_cost = a_len - a_index;
	else
		rrr_cost = b_len - b_index;
	return (rrr_cost);
}

// return the cost of rotating stack a and reverse rotating
// stack b
int	ra_rrb_p(int a_index, int b_index, int b_len)
{
	int	ra_rrb_cost;

	ra_rrb_cost = a_index + (b_len - b_index);
	return (ra_rrb_cost);
}

// return the cost of rotating stack b and reverse rotating
// stack a
int	rra_rb_p(int a_index, int a_len, int b_index)
{
	int	rra_rb_cost;

	rra_rb_cost = (a_len - a_index) + b_index;
	return (rra_rb_cost);
}
