#include <unistd.h>
#include <stdio.h>
#include "libft.h"

void freeList(t_list *head) {if (head) freeList(head->next); free(head);}
void * addOne(void * p) {void * r = malloc(sizeof(int)); *(int*)r = *(int*)p + 1; return (r);}

int main()
{
	int tab[] = {0, 1, 2, 3};
	t_list * l =  ft_lstnew(tab);

	for (int i = 1; i < 4; ++i)
		ft_lstadd_back(&l, ft_lstnew(tab + i));

	t_list * m = ft_lstmap(l, addOne, free);
	t_list * tmp = l;

	/* 1 2 3 4 */ for (int i = 0; i < 4; ++i)
	{
		printf("%d\n", *(int*)tmp->content);
		if (*(int*)tmp->content == i)
			write(1, "success", 7);
		else
			write(1, "fail", 4);
		tmp = tmp->next;
	}

	tmp = m;
	/* 5 6 7 8 */ for (int i = 0; i < 4; ++i)
	{
		printf("%d\n", *(int*)tmp->content);
		if (*(int*)tmp->content == i + 1)
			write(1, "success", 7);
		else
			write(1, "fail", 4);
		tmp = tmp->next;
	}
	freeList(l); ft_lstclear(&m, free);

	return 0;
}
