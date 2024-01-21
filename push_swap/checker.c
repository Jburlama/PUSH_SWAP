/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburlama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:23:14 by jburlama          #+#    #+#             */
/*   Updated: 2024/01/21 18:46:38 by jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
	cheker program recives a stack of number and reads the operations
	if the stack is sorted and the stack b is ampty printfs OK
	else prints KO
*/
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc <= 1 || !argv[1][0])
		return (1);
	if (argc == 2 && argv[1][0] != '\0')
		argv = ft_split(argv[1], ' ');
	else if (argc > 2)
		argv = argv + 1;
	if (argv == NULL)
		return (1);
	check_is_num(argv, argc == 2);
	stack_init(&stack_a, argv, argc == 2);
	read_output(&stack_a, &stack_b);
	if (is_sorted(stack_a) && stack_b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(&stack_a);
	if (stack_b != NULL)
		free_stack(&stack_b);
}

void	read_output(t_stack **a, t_stack **b)
{
	char	*output;

	output = NULL;
	while (42)
	{
		output = get_next_line(0);
		if (output == NULL)
			return ;
		operate(a, b, output);
		free(output);
	}
}

void	operate(t_stack **a, t_stack **b, char *op)
{
	if (ft_strcmp(op, "rrr\n") == 0)
		rrr(a, b, NULL);
	else if (ft_strcmp(op, "rra\n") == 0)
		reverse_rotate(a, NULL);
	else if (ft_strcmp(op, "rrb\n") == 0)
		reverse_rotate(b, NULL);
	else if (ft_strcmp(op, "sa\n") == 0)
		swap(a, NULL);
	else if (ft_strcmp(op, "sb\n") == 0)
		swap(b, NULL);
	else if (ft_strcmp(op, "pa\n") == 0)
		push(a, b, NULL);
	else if (ft_strcmp(op, "pb\n") == 0)
		push(b, a, NULL);
	else if (ft_strcmp(op, "ra\n") == 0)
		rotate(a, NULL);
	else if (ft_strcmp(op, "rb\n") == 0)
		rotate(b, NULL);
	else if (ft_strcmp(op, "rr\n") == 0)
		rr(a, b, NULL);
	else
	{
		write(2, "Error\n", 6);
		free_stacks(a, b, op);
	}
}

void	free_stacks(t_stack **a, t_stack **b, char *op)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	free(op);
	exit(1);
}
