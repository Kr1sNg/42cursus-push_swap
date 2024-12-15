/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 16:10:16 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/12/15 18:04:37 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


//swap: sa, sb
void	ft_swap(t_stack **head)
{
	t_stack	*temp;
	
	if (!(*head) || !(*head)->next)
		return (NULL);

	temp = *head;
	*head = ft_lstlast(*head);
	(*head)->next = temp;
	*head = temp->next;
	temp->next = NULL;
}

void	ft_push(t_stack	*dest, t_stack *src)
{
	int	temp;
	
	
}