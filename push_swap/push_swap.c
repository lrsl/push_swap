/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:23:44 by rroussel          #+#    #+#             */
/*   Updated: 2023/02/14 14:09:17 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include <stdio.h>

void	sort(t_list **a, t_list **b, t_data *data)
{
	if (data->total_nb == 2)
		(ft_putstr_fd("sa\n", STDOUT_FILENO), sa(a, b));
	else if (data->total_nb == 3)
		sorting_3(a, b, data, 3);
	else if (data->total_nb == 5)
		sorting_5(a, b, data);
	else
		sorting_big_stack(a, b, data);
}

void	set_data(t_data **data, long int len)
{
	(*data)->total_nb = len;
	(*data)->size = (*data)->total_nb / 2;
	if (len > 36)
		(*data)->max_value = 12 + ((*data)->total_nb / 33);
	else
		(*data)->max_value = (*data)->total_nb / 3;
	(*data)->start = 0;
}

int	main(int argc, char **argv)
{
	int		*tmp_tab;
	t_data	*data;
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2)
		return (0);
	tmp_tab = ft_parsing(argv + 1, argc - 1);
	if (!tmp_tab)
		return (ft_putstr_fd("Error\n", STDERR_FILENO), 0);
	stack_a = initialize_stack(tmp_tab, (long int)argc - 1);
	stack_b = NULL;
	if (check_is_sorted(stack_a))
		return (clear_stack(stack_a), free(tmp_tab), 0);
	data = malloc(sizeof(t_data));
	if (!data)
		return (clear_stack(stack_a), free(tmp_tab), 0);
	set_data(&data, argc - 1);
	sort(&stack_a, &stack_b, data);
	return (clear_stack(stack_a), clear_stack(stack_b),
		free(data), free(tmp_tab), 0);
}
