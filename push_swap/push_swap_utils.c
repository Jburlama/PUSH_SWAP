/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburlama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:37:35 by jburlama          #+#    #+#             */
/*   Updated: 2024/01/16 18:03:23 by jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// covert string to long
long	ft_atol(char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -sign;
	}
	while (str[i])
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

// iterate over stack, return true if is sorted, false if is not
bool	is_sorted(t_stack *head)
{
	t_stack	*ptr;

	if (head == NULL || head->next == NULL)
		return (true);
	while (head->next)
	{
		ptr = head->next;
		while (ptr)
		{
			if (head->number > ptr->number)
				return (false);
			ptr = ptr->next;
		}
		head = head->next;
	}
	return (true);
}

// iterates over the stack and return the size
int	stack_len(t_stack *head)
{
	int	len;

	len = 0;
	while (head)
	{
		head = head->next;
		len++;
	}
	return (len);
}

// return the node with highest value
t_stack	*get_max_value_node(t_stack *head)
{
	t_stack	*target;

	target = head;
	while (head)
	{
		if (head->number > target->number)
			target = head;
		head = head->next;
	}
	return (target);
}

// return the node with loest value
t_stack	*get_min_value_node(t_stack *head)
{
	t_stack	*target;

	target = head;
	while (head)
	{
		if (head->number < target->number)
			target = head;
		head = head->next;
	}
	return (target);
}
