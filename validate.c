/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 00:02:28 by malourei          #+#    #+#             */
/*   Updated: 2024/11/06 19:16:28 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	validate_len(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '9')
		{
			i++;
			j++;
		}
		else
			i++;
		if (j < 12)
			return (0);
	}
	return (1);
}

static int	validate_chars(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (str[i] == 0)
		return (1);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

static void	copy_args(char **args, t_list **lista, int argc)
{
	int		i;
	long	number;

	i = 1;
	while (i < argc)
	{
		number = ft_atol(args[i]);
		if (number == LONG_MIN)
		{
			ft_free_list(lista);
			exit(1);
		}
		ft_push(lista, (int)number);
		i++;
	}
}

static int	duplicates(t_list *lista)
{
	t_list	*top;
	t_list	*check_next;

	top = lista;
	while (top != NULL)
	{
		check_next = top->next;
		while (check_next != NULL)
		{
			if (top->value == check_next->value)
				return (1);
			check_next = check_next->next;
		}
		top = top->next;
	}
	return (0);
}

void	valide_args(char **args, t_list **numbers, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (validate_len(args[i]))
		{
			write(2, "ERROR\n", 6);
			exit(1);
		}
		if (validate_chars(args[i]))
		{
			write(2, "ERROR\n", 6);
			exit(1);
		}
		i++;
	}
	copy_args(args, numbers, argc);
	if (duplicates(*numbers) == 1)
	{
		write(2, "ERROR\n", 6);
		ft_free_list(numbers);
		exit(1);
	}
}
