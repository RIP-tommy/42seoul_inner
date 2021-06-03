/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 20:11:53 by sungmcho          #+#    #+#             */
/*   Updated: 2021/06/02 20:43:56 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft.h"

static	int		check_sign(char c)
{
	if (c == '+')
		return (1);
	else if (c == '-')
		return (-1);
	else
		return (0);
}

int				ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	rslt;

	i = 0;
	sign = 1;
	rslt = 0;
	while (((9 <= str[i]) && (str[i] <= 13)) || str[i] == ' ')
		i++;
	while (check_sign(str[i]) != 0)
	{
		sign *= check_sign(str[i]);
		i++;
	}
	while (ft_isdigit(str[i]) != 0)
	{
		rslt = rslt * 10 + ((str[i] - '0') * sign);
		i++;
	}
	return (rslt);
}
