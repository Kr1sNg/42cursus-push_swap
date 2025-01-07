/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 16:10:16 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/07 20:16:26 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//push: pa, pb: take the first element at the top of b/a and put it at the top of a /b
static void	push(t_stack **dest, t_stack **src)
{
	t_stack	*push_node;
	
	if (!*src)
		return ;
	push_node = *src;
	*src = (*src)
}

//rotate: ra, rb, rr: shift up all element by 1. The first become the last
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

// void	ft_push(t_stack	*dest, t_stack *src)
// {
// 	int	temp;
	
	
// }

// rra, rrb, rrr: shift down all element by 1. The last become the first

int	main(void)
{

}