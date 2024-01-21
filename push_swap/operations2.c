/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburlama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 20:35:30 by jburlama          #+#    #+#             */
/*   Updated: 2024/01/21 17:44:06 by jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// the last element becomes the first one, the first becomes the second
void	reverse_rotate(t_stack **head, char *operation)
{
	t_stack	*tail;
	t_stack	*ptr;

	tail = *head;
	if (tail == NULL || tail->next == NULL)
		return ;
	while (tail->next->next)
		tail = tail->next;
	ptr = tail->next;
	tail->next = NULL;
	ptr->next = *head;
	*head = ptr;
	if (operation)
		ft_printf("%s\n", operation);
}

// reverse rotate a && b
void	rrr(t_stack **stack_a, t_stack **stack_b, char *operation)
{
	if (stack_a)
		reverse_rotate(stack_a, NULL);
	if (stack_b)
		reverse_rotate(stack_b, NULL);
	if (operation)
		ft_printf("%s\n", operation);
}
