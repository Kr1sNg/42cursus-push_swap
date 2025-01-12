/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 22:24:48 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/09 17:41:52 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  ft_error_ return (-42) means ERROR, return (0) means OK 
*/

#include "../../includes/push_swap.h"

int	ft_error_input(char *str)
{
	int	i;

	if (str[0] != '+' && str[0] != '-' && !ft_isdigit(str[0]))
		return (-42);
	if (str[0] == '+' || str[0] == '-')
	{
		if (!ft_isdigit(str[1]))
			return (-42);
	}
	i = 1;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (-42);
		i++;
	}
	return (0);
}

int	ft_error_dup(t_stack *a, int n)
{
	if (a == NULL)
		return (0);
	while (a != NULL)
	{
		if (a->nbr == n)
			return (-42);
		a = a->next;
	}
	return (0);
}

void	ft_stack_clear(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*curr;

	if (stack == NULL)
		return ;
	curr = *stack;
	while (curr != NULL)
	{
		tmp = curr->next;
		curr->nbr = 0;
		free(curr);
		curr = tmp;
	}
	*stack = NULL;
}

void	ft_exit(t_stack **a)
{
	ft_stack_clear(a);
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}
