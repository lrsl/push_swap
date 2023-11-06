/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:00:52 by rroussel          #+#    #+#             */
/*   Updated: 2023/02/14 14:05:10 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include "push_swap.h"

const struct s_oper {
	const char	*name;
	void		(*func)(t_list **, t_list **);
}	oper_name_func [12] = {
		{"pa\n", pa},
		{"pb\n", pb},
		{"ra\n", ra},
		{"rb\n", rb},
		{"rr\n", rr},
		{"sa\n", sa},
		{"sb\n", sb},
		{"ss\n", ss},
		{"rra\n", rra},
		{"rrb\n", rrb},
		{"rrr\n", rrr},
		{NULL, NULL}
};

#endif
