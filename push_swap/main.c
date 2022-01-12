/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:24:08 by sungmcho          #+#    #+#             */
/*   Updated: 2022/01/12 12:38:24 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	int_checker(char *str)
{
	if (*str == '-')
		str++;
	while (*str)
	{
		if ((*str < '0') || ('9' < *str))
			exit_function();
		str++;
	}
}

static void	dup_checker(char *s1, char *s2)
{
	int	len;

	if (ft_strlen(s1) > ft_strlen(s2))
		len = ft_strlen(s1);
	else
		len = ft_strlen(s2);
	if (ft_strncmp(s1, s2, len) == 0)
		exit_function();
}

static void	error_checker(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	if (ac < 2)
		exit_function();
	else
	{
		while (i < ac)
		{
			int_checker(av[i]);
			over_max_min_int_checker(av[i]);
			j = i + 1;
			while (j < ac)
			{
				dup_checker(av[i], av[j]);
				j++;
			}
			i++;
		}
	}
}

static void	init_stack(t_stack *stack, int ac, char **av)
{
	int	i;

	i = 0;
	stack->a_stack = (int *)malloc(sizeof(int) * ac);
	stack->b_stack = (int *)malloc(sizeof(int) * ac);
	if (!stack->a_stack || !stack->b_stack)
		exit_function();
	stack->a_len = ac - 1;
	stack->b_len = 0;
	while (i < ac - 1)
	{
		stack->a_stack[i] = ft_atoi(av[i + 1]);
		stack->b_stack[i] = '\0';
		i++;
	}
	stack->a_stack[i] = '\0';
	stack->b_stack[i] = '\0';
	stack->sort_len = 0;
	stack->min_sorted = 0;
}

int	main(int ac, char **av)
{
	t_stack	stack;
	t_stack	*s_ptr;

	error_checker(ac, av);
	s_ptr = &stack;
	init_stack(s_ptr, ac, av);
	if (!is_sorted_asc(stack.a_stack, stack.a_len) || \
		!is_sorted_desc(stack.a_stack, stack.a_len))
		sort(s_ptr);
	free(stack.a_stack);
	free(stack.b_stack);
	return (0);
}
