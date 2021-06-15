/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 18:39:00 by sungmcho          #+#    #+#             */
/*   Updated: 2021/06/14 21:20:16 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdelone(t_list *lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst)
		return ;
	temp = lst->next;
	del(lst->content);
	free(lst);
	lst = temp;
}
