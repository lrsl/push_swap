/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:00:43 by rroussel          #+#    #+#             */
/*   Updated: 2023/02/14 14:04:40 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include "../includes/push_swap.h"

static int	execute_step(t_list **a, t_list **b, const char *step)
{
	int	i;

	i = 0;
	while (oper_name_func[i].name
		&& ft_strncmp(oper_name_func[i].name, step, ft_strlen(step)))
		i++;
	if (oper_name_func[i].func)
		return (oper_name_func[i].func(a, b), 1);
	else
		return (0);
}

static int	read_instructions(t_list **a, t_list **b)
{
	char	*line;
	int		return_value;

	return_value = 1;
	line = get_next_line(STDIN_FILENO);
	if (!line)
		return (1);
	if (!ft_strncmp(line, "\n", 1))
		return (free(line), 1);
	while (line)
	{
		return_value = execute_step(a, b, line);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	return (return_value);
}

int	main(int argc, char **argv)
{
	int		*arr;
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2)
		return (0);
	arr = ft_parsing(argv + 1, argc - 1);
	if (!arr)
		return (ft_putstr_fd("Error\n", STDERR_FILENO), 0);
	stack_a = initialize_stack(arr, argc - 1);
	stack_b = NULL;
	if (!read_instructions(&stack_a, &stack_b))
		return (ft_putstr_fd("Error\n", STDERR_FILENO),
			clear_stack(stack_a), clear_stack(stack_b), free(arr), 0);
	if (check_is_sorted(stack_a) && !stack_b)
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	else
		ft_putstr_fd("KO\n", STDOUT_FILENO);
	return (clear_stack(stack_a), clear_stack(stack_b), free(arr), 0);
}
