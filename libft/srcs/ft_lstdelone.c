#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst && del)
	{
		(*del)(lst->content);
		free(lst);
	}
}
/*
int main(void)
{
    t_list  *a = ft_lstnew(malloc(1));
    ft_lstdelone(a, free);
    a = 0;
}*/
