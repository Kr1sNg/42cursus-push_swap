/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 22:25:45 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/07 19:57:30 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	stack_add_back(t_stack **head, int n)
{
	t_stack	*new_node;
	t_stack	*tail; // to append to

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return;
	new_node->next = NULL;
	new_node->nbr = n;
	if (!(*head))
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		tail = *head;
		while (tail->next != NULL)
			tail = tail->next;
		tail->next = new_node;
		new_node->prev = tail;
	}
}

void	init_stack_a(t_stack **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i])) //TODO
			free_errors(a); //TODO
		n = ft_atol(argv[i]); //TODO
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a);
		if (error_duplicate(*a, (int)n)) //TODO
			free_errors(a);
		stack_add_back(a, (int)n); // list_add_back to have first argument be at the top of stack
		i++;
	}
}

bool	is_stack_sorted(t_stack *stack)
{
	if (!stack)
		return (-42);
	while (stack->next != NULL)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, true); //TODO
			else
				rra(stack, true); //TODO
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, true); //TODO
			else
				rrb(stack, true); //TODO
		}
	}
}