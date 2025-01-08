/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:40:46 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/08 22:18:55 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// we can put ./push_swap "12 345 56 34"
// or ./push_swap 12 345 56 34
// so it's not valid with 

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**arrs;
	
	a = NULL;
	b = NULL;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (ft_printf("Usage: %s <list of intergers>\n", argv[0]));
	else if (argc == 2)
	{
		arrs = ft_split(argv[1], ' ');
		init_stack_a(&a, arrs);
	}
	else
		init_stack_a(&a, argv + 1);
	if (!is_stack_sorted(a))
	{
		if (ft_stack_len(a) == 2)
			sa(&a, true);
		else if (ft_stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	if (argc == 2)
		ft_split_free(arrs);
	free_stack(&a);
	return (0);
}

