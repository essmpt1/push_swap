/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 00:01:33 by malourei          #+#    #+#             */
/*   Updated: 2024/11/07 18:48:27 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	validate_until_sort_5(t_list **stack_a, t_list **stack_b)
{
	if (is_sorted(stack_a))
		return ;
	if (ft_size(stack_a) == 2)
		swap_a(stack_a);
	else if (ft_size(stack_a) == 3)
		ft_sort_3(stack_a);
	else if (ft_size(stack_a) == 4)
		ft_sort_4(stack_a, stack_b);
	else if (ft_size(stack_a) == 5)
		ft_sort_5(stack_a, stack_b);
}

int	main(int argc, char *argv[])
{
	t_list	*lista;
	t_list	*listb;

	if (argc == 1)
		return (1);
	lista = NULL;
	listb = NULL;
	valide_args(argv, &lista, argc);
	if (argc < 7)
		validate_until_sort_5(&lista, &listb);
	else
		ft_init_sort(&lista, &listb);
	ft_print_list(lista);
	ft_free_list(&lista);
	return (0);
}
