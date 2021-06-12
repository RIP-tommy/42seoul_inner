#include "libft.h"

void		ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	current = *lst;
	while (current)
	{
		current = current -> next;
	}
	current->next = new;
}
