#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*new_list;

	new_list = *lst;
	if (new_list == NULL)
		*lst = new;
	else
	{
		while (new_list->next)
			new_list = new_list->next;
		new_list->next = new;
	}
}
/*
void	freeList(t_list *head)
{
	if (head)
	{
		freeList((t_list *)head->next);
		free(head);
	}
}

int	main(void)
{
	t_list	*a = NULL;
	t_list	*b = NULL;
	t_list	*c = NULL;

	ft_lstadd_back(&a, ft_lstnew((void*)1));
	printf("1. %s\n", a->content == (void*)1 ? "Y" : "N");
	printf("2. %s\n", a->next == 0 ? "Y" : "N");
	
	ft_lstadd_back(&a, ft_lstnew((void*)2));
	c = a;
	printf("3. %s\n", a->content == (void*)1 ? "Y" : "N");
	a = a->next;
	printf("4. %s\n", a->content == (void*)2 ? "Y" : "N");
	printf("5. %s\n", a->next == 0 ? "Y" : "N");
	
	ft_lstadd_back(&b, ft_lstnew((void*)3));
	ft_lstadd_back(&b, ft_lstnew((void*)4));
	ft_lstadd_back(&c, b);
	printf("6. %s\n", c->content == (void*)1 ? "Y" : "N");
	c = c->next;
	printf("7. %s\n", c->content == (void*)2 ? "Y" : "N");
	c = c->next;
	printf("8. %s\n", c->content == (void*)3 ? "Y" : "N");
	c = c->next;
	printf("9. %s\n", c->content == (void*)4 ? "Y" : "N");
	printf("10. %s\n", c->next == 0 ? "Y" : "N");

	//freeList (a);
	//printf("free a");
	//freeList (b);
	//printf("free b");
	freeList (c);
	printf("free c");
}*/
