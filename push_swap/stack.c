/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburlama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 21:28:26 by jburlama          #+#    #+#             */
/*   Updated: 2024/01/10 03:08:29 by jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	iterates over argv
		call ft_atol;
			free_all if interger overflow;
		call stack_add_last
			free_all if return NULL
	call check_duplicats
		free_all if true
	free_argv if is on heep
*/
void	stack_init(t_stack **stack_a, char **argv, bool is_heep)
{
	int		i;
	long	n;

	i = 0;
	while (argv[i])
	{
		n = ft_atol(argv[i]);
		if (n < INT_MIN || n > INT_MAX)
		{
			ft_putstr_fd("Error\n", 2);
			free_all(stack_a, argv, is_heep);
		}
		*stack_a = stack_add_last(stack_a, n);
		if (*stack_a == NULL)
			free_all(stack_a, argv, is_heep);
		i++;
	}
	if (check_duplicates(*stack_a))
	{
		ft_putstr_fd("Error\n", 2);
		free_all(stack_a, argv, is_heep);
	}
	if (is_heep)
		free_argv(argv);
}

/*
	add nodes to the end of stack, and will create new one if is empty
		return null if malloc fails
*/
t_stack	*stack_add_last(t_stack **stack_a, int n)
{
	t_stack	*head;
	t_stack	*ptr;

	head = *stack_a;
	if (head == NULL)
	{
		head = ft_calloc(sizeof(*head), 1);
		if (head == NULL)
			return (NULL);
		head->number = n;
		return (head);
	}
	ptr = head;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = ft_calloc(sizeof(*head), 1);
	if (ptr->next == NULL)
		return (NULL);
	ptr->next->number = n;
	return (head);
}

// iterate over argv and check for non numeric charactors, 
void	check_is_num(char **argv, bool is_heep)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				ft_putstr_fd("Error\n", 2);
				if (is_heep)
					free_argv(argv);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

/* 
	iterate over stack
	 return true of there is duplicates, and false other wise
*/
bool	check_duplicates(t_stack *head)
{
	t_stack	*ptr;

	while (head->next)
	{
		ptr = head->next;
		while (ptr)
		{
			if (head->number == ptr->number)
				return (true);
			ptr = ptr->next;
		}
		head = head->next;
	}
	return (false);
}
