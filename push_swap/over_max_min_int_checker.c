/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   over_max_min_int_checker.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:24:17 by sungmcho          #+#    #+#             */
/*   Updated: 2022/01/09 14:58:03 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static	int	check_sign(char c)
{
	if (c == '+')
		return (1);
	else if (c == '-')
		return (-1);
	else
		return (0);
}

void	over_max_min_int_checker(char *str)
{
	int		i;
	int		sign;
	size_t	rslt;

	i = 0;
	sign = 1;
	rslt = 0;
	while (((9 <= str[i]) && (str[i] <= 13)) || str[i] == ' ')
		i++;
	if (check_sign(str[i]) != 0)
	{
		sign *= check_sign(str[i]);
		i++;
	}
	while (ft_isdigit(str[i]) != 0)
	{
		rslt = rslt * 10 + ((str[i] - '0'));
		if (sign > 0 && rslt > 2147483647)
			exit_function();
		if (sign < 0 && rslt > 2147483648)
			exit_function();
		i++;
	}
}
