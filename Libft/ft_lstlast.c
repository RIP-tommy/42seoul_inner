/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 19:48:12 by sungmcho          #+#    #+#             */
/*   Updated: 2021/06/12 21:39:09 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstlast(t_list *lst)
{
	t_list	*current;

	current = lst;
	while (current)
	{
		current = current->next;
	}
	current = lst->next;
	return (current);
}
