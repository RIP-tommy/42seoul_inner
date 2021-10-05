/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho@student.42.kr <sungmcho@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:51:28 by sungmcho@st       #+#    #+#             */
/*   Updated: 2021/10/05 13:51:30 by sungmcho@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/ft_printf.h"
#include <signal.h>

int	main(void)
{
	char	*s1;

	ft_printf("%d\n", getpid());
	return (0);
}
