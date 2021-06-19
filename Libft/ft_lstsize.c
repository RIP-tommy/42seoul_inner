/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 19:47:28 by sungmcho          #+#    #+#             */
/*   Updated: 2021/06/17 11:44:47 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	t_list	*current;
	int		len;

	if (!(lst->content))
		return (-1);
	len = 0;
	current = lst;
	while (current)
	{
		current = current->next;
		len++;
	}
	return (len);
}
