/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburlama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 23:03:55 by jburlama          #+#    #+#             */
/*   Updated: 2024/01/08 23:11:46 by jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// free argv, does't check if is on heep, dosn's exit the program
void	free_argv(char **argv)
{
	int	i;

	i = 0;
	if (argv == NULL)
		return ;
	while (argv[i])
	{
		free(argv[i]);
		argv[i] = NULL;
		i++;
	}
	free(argv);
	argv = NULL;
}

// free all heap memory, exit the program
void	free_all(t_stack **stack_a, char **argv, bool is_heep)
{
	if (is_heep)
		free_argv(argv);
	free_stack(stack_a);
	exit(1);
}

// free stack, does not exit the program
void	free_stack(t_stack **stack_a)
{
	t_stack	*ptr;

	ptr = *stack_a;
	while (ptr)
	{
		*stack_a = (*stack_a)->next;
		free(ptr);
		ptr = *stack_a;
	}
	return ;
}
