/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:40:46 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/10 13:57:26 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	TURC ALGORITHM
**	1. pb 2 times
**	2. Find cheapest nbr and pb (in order)
**		if this nbr will be the new biggest or smallest of b,
**		place it just above the old biggest
**	3. Sort last 3 numbers in a
**	4. pa in correct position, if not, ra until it comes up
*/

#include "../../includes/push_swap.h"

// int	main(int argc, char **argv)
// {
// 	t_stack	*a;
// 	t_stack	*b;
// 	char	**arrs;

// 	a = NULL;
// 	b = NULL;
// 	if (argc < 2 || (argc == 2 && !argv[1][0]))
// 		return (0);
// 	else if (argc == 2)
// 	{
// 		arrs = ft_split(argv[1], ' ');
// 		ft_stack_init(&a, arrs);
// 	}
// 	else
// 		ft_stack_init(&a, argv + 1);
// 	if (!ft_isstacksorted(a))
// 		ft_sorting(&a, &b);
// 	if (argc == 2)
// 		ft_split_free(arrs);
// 	ft_stack_clear(&a);
// 	return (0);
// }

void	ft_sorting(t_stack **a, t_stack **b)
{
	if (ft_stack_size(*a) == 2)
		sa(a, true);
	else if (ft_stack_size(*a) == 3)
		ft_sort_three(a);
	else
		ft_sort_bigger(a, b);
}

void	ft_sort_three(t_stack **a)
{
	t_stack	*biggest_node;

	biggest_node = ft_stack_max(*a);
	if (biggest_node == *a)
		ra(a, true);
	else if (biggest_node == (*a)->next)
		rra(a, true);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, true);
}

void	ft_sort_bigger(t_stack **a, t_stack **b)
{
	int	len_a;
	int	i;

	len_a = ft_stack_size(*a);
	i = 0;
	while (i < 2 && len_a > 3 && !ft_isstacksorted(*a))
	{
		pb(b, a, true);
		len_a--;
		i++;
	}
	while (len_a > 3 && !ft_isstacksorted(*a))
	{
		ft_node_init_a(*a, *b);
		ft_move_a_to_b(a, b);
		len_a--;
	}
	ft_sort_three(a);
	while (*b != NULL)
	{
		ft_node_init_b(*a, *b);
		ft_move_b_to_a(a, b);
	}
	ft_node_set_index(*a);
	ft_move_min_to_top(a);
}
