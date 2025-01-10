/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:40:46 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/10 14:28:59 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** we use "Ctrl + d" to inform to Terminal that this is EOF
*/

// #include "../../includes/checker.h"
#include "../../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**arrs;
	t_list	*instructions;

	a = NULL;
	b = NULL;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		exit(EXIT_FAILURE);
	else if (argc == 2)
	{
		arrs = ft_split(argv[1], ' ');
		ft_stack_init(&a, arrs);
	}
	else
		ft_stack_init(&a, argv + 1);
	read_and_execute(&instructions, STDIN_FILENO); // read_op(&data)
	
	// if (ft_isstacksorted(a))
	// 	ft_printf("OK\n");
	// else
	// 	ft_printf("Need to sort\n");
	if (argc == 2)
		ft_split_free(arrs);
	ft_stack_clear(&a);
	return (0);
}

void read_and_execute(t_list **instructions, int fd)
{
	char *line;

	while (line != NULL)
	{
		line = get_next_line(fd);
		ft_check_error_instructions(line);
		
	}
	
	
	
}

void	ft_error_op(char *op)
{
	if (!ft_strcmp(op, "sa"))
		return (ft_printf("Error\n"));
	else if (!ft_strcmp(op, "sb"))
		return (ft_printf("Error\n"));
	else if (!ft_strcmp(op, "sb"))
		return (ft_printf("Error\n"));
	else if (!ft_strcmp(op, "sb"))
		return (ft_printf("Error\n"));
	else if (!ft_strcmp(op, "sb"))
		return (ft_printf("Error\n"));
	else if (!ft_strcmp(op, "sb"))
		return (ft_printf("Error\n"));
	else if (!ft_strcmp(op, "sb"))
		return (ft_printf("Error\n"));
	else if (!ft_strcmp(op, "sb"))
		return (ft_printf("Error\n"));
	else if (!ft_strcmp(op, "sb"))
		return (ft_printf("Error\n"));
	else if (!ft_strcmp(op, "sb"))
		return (ft_printf("Error\n"));
	else if (!ft_strcmp(op, "sb"))
		return (ft_printf("Error\n"));
		
}

