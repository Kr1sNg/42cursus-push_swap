/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 16:10:16 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/12/16 16:16:20 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"



//swap: sa, sb

void	ft_swap(t_stack **head, char print)
{
	
}

//push


//rotate: ra, rb
void	ft_rotate(t_stack **head, char print)
{
	t_stack	*temp;
	
	if (!(*head) || !(*head)->next)
		return (NULL);

	temp = *head;
	*head = ft_lstlast(*head);
	(*head)->next = temp;
	*head = temp->next;
	temp->next = NULL;
	if (print == 1)
		write(1, "ra\n", 3);
}

void	ft_push(t_stack	*dest, t_stack *src)
{
	int	temp;
	
	
}