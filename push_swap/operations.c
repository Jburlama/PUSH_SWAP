/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburlama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 19:02:53 by jburlama          #+#    #+#             */
/*   Updated: 2024/01/18 18:21:50 by jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	push top of src to top of dest
		do nothing if src if empty
*/
void	push(t_stack **dest, t_stack **src, char *operation)
{
	t_stack	*ptr;

	if (*src == NULL)
		return ;
	ptr = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = ptr;
	if (operation)
		ft_printf("%s\n", operation);
}

// swap the first two elements of the stack
void	swap(t_stack **head, char *operation)
{
	t_stack	*ptr;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	ptr = (*head)->next;
	(*head)->next = ptr->next;
	ptr->next = *head;
	*head = ptr;
	if (operation)
		ft_printf("%s\n", operation);
}

//	swap a && b
void	ss(t_stack **stack_a, t_stack **stack_b, char *operation)
{
	if (stack_a)
		swap(stack_a, NULL);
	if (stack_b)
		swap(stack_b, NULL);
	if (operation)
		ft_printf("%s\n", operation);
}

// the first element becames the last, the second becomes the first
void	rotate(t_stack **head, char *operation)
{
	t_stack	*ptr;
	t_stack	*tail;

	ptr = *head;
	if (ptr == NULL || ptr->next == NULL)
		return ;
	ptr = ptr->next;
	(*head)->next = NULL;
	tail = ptr;
	while (tail->next)
		tail = tail->next;
	tail->next = *head;
	*head = ptr;
	if (operation)
		ft_printf("%s\n", operation);
}

//	rotate a && b
void	rr(t_stack **stack_a, t_stack **stack_b, char *operation)
{
	if (stack_a)
		rotate(stack_a, NULL);
	if (stack_b)
		rotate(stack_b, NULL);
	if (operation)
		ft_printf("%s\n", operation);
}
