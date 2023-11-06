/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:23:53 by rroussel          #+#    #+#             */
/*   Updated: 2023/02/14 14:05:27 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>

typedef struct s_data
{
	int			max_value;
	long int	size;
	int			start;
	long int	total_nb;
}				t_data;

int				*ft_parsing(char **ints, int len);

t_list			*initialize_stack(int *src, long int len);
void			clear_stack(t_list *lst);
void			delete(void *content);
int				check_is_sorted(t_list *a);
int				check_empty_string_or_max_int(char **av, int ac);
int				check_only_valid_int(char **av, int ac);
int				emptystring(char **av, int ac);

void			sorting_big_stack(t_list **a, t_list **b, t_data *data);
void			sorting_3(t_list **a, t_list **b, t_data *data, int max);
void			sorting_5(t_list **a, t_list **b, t_data *data);

void			pa(t_list **a, t_list **b);
void			pb(t_list **a, t_list **b);

void			sa(t_list **a, t_list **b);
void			sb(t_list **a, t_list **b);
void			ss(t_list **a, t_list **b);

void			ra(t_list **a, t_list **b);
void			rb(t_list **a, t_list **b);
void			rr(t_list **a, t_list **b);

void			rra(t_list **a, t_list **b);
void			rrb(t_list **a, t_list **b);
void			rrr(t_list **a, t_list **b);

#endif
