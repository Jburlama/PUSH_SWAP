/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburlama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:42:56 by jburlama          #+#    #+#             */
/*   Updated: 2024/01/21 18:29:09 by jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"
# include "get_next_line/get_next_line.h"

void	checker(void);
void	operate(t_stack **a, t_stack **b, char *op);
void	read_output(t_stack **a, t_stack **b);
void	free_stacks(t_stack **a, t_stack **b, char *op);
int		ft_strcmp(char *s1, char *s2);

#endif
