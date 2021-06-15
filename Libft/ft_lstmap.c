/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 18:53:03 by sungmcho          #+#    #+#             */
/*   Updated: 2021/06/16 01:44:07 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list  *new;
    t_list  *temp;
    t_list  *last;

    if (!(new = ft_lstnew(f(lst->content))))
        return (NULL);
    last = new;
    lst = lst->next;
	while (lst)
	{
	    if(!(temp = ft_lstnew(f(lst->content))))
    	{
    		ft_lstclear(&lst, del);
	    	return (NULL);
	    }
        last->next = temp;
        last = temp;
		lst = lst->next;
	}
	return (new);
}
