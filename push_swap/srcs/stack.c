/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 22:25:45 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/06 00:02:19 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	append_node(t_stack_node **head, int n)
{
	t_stack_node	*new_node;
	t_stack_node	*tail; // to append to

	new_node = malloc(sizeof(t_stack_node));
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

void	init_stack_a(t_stack_node **a, char **argv)
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
		append_node(a, (int)n); // list_add_back to have first argument be at the top of stack
		i++;
	}
}