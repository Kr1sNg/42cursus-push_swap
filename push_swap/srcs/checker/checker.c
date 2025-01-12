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

#include "../../includes/checker.h"

int	ft_iserrorop(char *op, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(op, "sa") || !ft_strcmp(op, "sa\n"))
		return (sa(a, false), 0);
	else if (!ft_strcmp(op, "sb") || !ft_strcmp(op, "sb\n"))
		return (sb(b, false), 0);
	else if (!ft_strcmp(op, "ss") || !ft_strcmp(op, "ss\n"))
		return (ss(a, b, false), 0);
	else if (!ft_strcmp(op, "pa") || !ft_strcmp(op, "pa\n"))
		return (pa(a, b, false), 0);
	else if (!ft_strcmp(op, "pb") || !ft_strcmp(op, "pb\n"))
		return (pb(b, a, false), 0);
	else if (!ft_strcmp(op, "ra") || !ft_strcmp(op, "ra\n"))
		return (ra(a, false), 0);
	else if (!ft_strcmp(op, "rb") || !ft_strcmp(op, "rb\n"))
		return (rb(b, false), 0);
	else if (!ft_strcmp(op, "rr") || !ft_strcmp(op, "rr\n"))
		return (rr(a, b, false), 0);
	else if (!ft_strcmp(op, "rra") || !ft_strcmp(op, "rra\n"))
		return (rra(a, false), 0);
	else if (!ft_strcmp(op, "rrb") || !ft_strcmp(op, "rrb\n"))
		return (rrb(b, false), 0);
	else if (!ft_strcmp(op, "rrr") || !ft_strcmp(op, "rrr\n"))
		return (rrr(a, b, false), 0);
	else
		return (ft_printf("Error\n"), -42);
}

int	ft_execuse(t_list *instruction, t_stack **a, t_stack **b)
{
	t_list	*curr;
	int		check;

	curr = instruction;
	if (instruction == NULL)
		return (-42);
	while (curr != NULL)
	{
		check = ft_iserrorop(curr->data, a, b);
		if (check != 0)
			return (-42);
		curr = curr->next;
	}
	return (0);
}

void	read_and_execute(int fd, t_stack **a, t_stack **b)
{
	char	*line;
	t_list	*instructions;
	int		exe;

	instructions = NULL;
	line = get_next_line(fd);
	if (!line)
	{
		if (ft_isstacksorted(*a) && *b == NULL)
			ft_printf("OK\n");
	}
	while (line != NULL)
	{
		ft_list_push_back(&instructions, line);
		line = get_next_line(fd);
	}
	exe = ft_execuse(instructions, a, b);
	if (exe == 0)
	{
		if (ft_isstacksorted(*a) && *b == NULL)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	ft_list_clear_fct(instructions, free);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**arrs;

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
	read_and_execute(STDIN_FILENO, &a, &b);
	if (b != NULL)
		ft_stack_clear(&b);
	if (argc == 2)
		ft_split_free(arrs);
	return (ft_stack_clear(&a), 0);
}
