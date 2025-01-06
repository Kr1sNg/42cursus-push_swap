/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:40:46 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/05 23:44:58 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// we can put ./push_swap "12 345 56 34"
// or ./push_swap 12 345 56 34
// so it's not valid with 



int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**arrs;
	
	a = NULL;
	b = NULL;
	if (argc < 2 || (argc == 2 && !argv[1][0])) //?can change to && !argv[1]?
		return (ft_printf("Usage: ./%s <list of intergers>", argv[0]));
	else if (argc == 2)
	{
		arrs = ft_split(argv[1], ' ');
		init_stack_a(&a, arrs);
	}
	else  //TO-CHECK if it works with my ft_split
		init_stack_a(&a, argv + 1);
	if (!stack_sorted(a)) //TODO // co the lam sort_main(&a, &b) roi check de vua 25 lines
	{	// do we need to check if len = 1?
		if (stack_len(a) == 2) //TODO
			sa(&a, false); //TODO
		else if (stack_len(a) == 3)
			sort_three(&a); //TODO
		else
			sort_stacks(&a, &b); //TODO
	}
	free_stack(&a);
	return (0);
}