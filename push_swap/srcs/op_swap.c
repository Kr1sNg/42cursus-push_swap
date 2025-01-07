/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 16:10:16 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/04 17:36:13 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"



//swap: sa, sb, ss: swap the first 2 elements at the top (head of list) of stack

void	ft_swap_elem(t_stack **head, char print)
{
	t_stack *tmp;

	tmp->next = (*head)->next;
	tmp->prev = *head;
	(*head)->next = tmp;
	





}

//push: pa, pb: take the first element at the top of b/a and put it at the top of a /b


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