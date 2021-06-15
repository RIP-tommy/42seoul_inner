/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 18:53:03 by sungmcho          #+#    #+#             */
/*   Updated: 2021/06/15 18:22:47 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	while (lst)
	{
		if(!f(lst->content))
		{
			ft_lstclear(&lst, del);
			return (lst);
		}
		printf("%d\n", *(int *)(lst->content));
		lst = lst->next;
	}
	return (lst);
}
