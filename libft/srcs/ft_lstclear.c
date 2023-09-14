#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
    t_list  *a;
    t_list  *b;
    
    if (!(lst) || !(del))
        return ;
    a = *lst;
    while (a)
    {
        b = a->next;
        (*del)(a->content);
        free(a);
        a = b;
    }
    *lst = NULL;
}
