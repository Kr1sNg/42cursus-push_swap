/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:40:46 by tat-nguy          #+#    #+#             */
/*   Updated: 2025/01/10 17:31:36 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** we use "Ctrl + d" to inform to Terminal that this is EOF
*/

// #include "../../includes/checker.h"
#include "../../includes/push_swap.h"

int	ft_iserrorop(char *op)
{
	if (!ft_strcmp(op, "sa"))
		return (0);
	else if (!ft_strcmp(op, "sb"))
		return (0);
	else if (!ft_strcmp(op, "ss"))
		return (0);
	else if (!ft_strcmp(op, "pa"))
		return (0);
	else if (!ft_strcmp(op, "pb"))
		return (0);
	else if (!ft_strcmp(op, "ra"))
		return (0);
	else if (!ft_strcmp(op, "rb"))
		return (0);
	else if (!ft_strcmp(op, "rr"))
		return (0);
	else if (!ft_strcmp(op, "rra"))
		return (0);
	else if (!ft_strcmp(op, "rrb"))
		return (0);
	else if (!ft_strcmp(op, "rrr"))
		return (0);
	else
		return (-42);		
}

void ft_read_ops(t_list **instructions, int fd)
{
	char *line;
	char *op;

	while (line != NULL)
	{
		line = get_next_line(fd);
		op = ft_strtrim(line, "\n\0");
		ft_list_push_back(instructions, op);
	}
}

void ft_execuse(t_list *instruction)
{
	t_list	*curr;

	curr = instruction;
	if (instruction == NULL)
		return ;
	while (curr != NULL)
	{
		
		if (ft_iserrorop(curr->data))
		{
			ft_list_clear(instruction);
			ft_printf("Error OP\n");
			return ;
		}
		ft_printf("%s\n", curr->data);
		curr = curr->next;
	}
}


void	read_and_execute(int fd)
{
	t_list	*instructions;
	
	instructions = NULL;
	ft_read_ops(&instructions, fd);
	ft_execuse(instructions);
	ft_list_clear(instructions);
}


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
	read_and_execute(STDIN_FILENO); // read_op(&data)
	
	// if (ft_isstacksorted(a))
	// 	ft_printf("OK\n");
	// else
	// 	ft_printf("Need to sort\n");
	if (argc == 2)
		ft_split_free(arrs);
	return (ft_stack_clear(&a), 0);
}






