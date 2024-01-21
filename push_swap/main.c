/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburlama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:09:46 by jburlama          #+#    #+#             */
/*   Updated: 2024/01/21 18:21:58 by jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	checks for number of argumets;
		if is two
			call split;
		else
			point argv to argv + 1;
	check is argumets are numeric values
		free's argv if is not, and exit the program;
	call stack_init to initialize stack a;
	sort stack if is not sorted
	free_stack
*/
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc <= 1 || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		argv = argv + 1;
	if (argv == NULL)
		return (1);
	check_is_num(argv, argc == 2);
	stack_init(&stack_a, argv, argc == 2);
	if (!is_sorted(stack_a))
	{
		if (stack_len(stack_a) == 2)
			swap(&stack_a, "sa");
		else if (stack_len(stack_a) == 3)
			sort_three(&stack_a);
		else
			push_swap(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
}

void	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit (1);
}
