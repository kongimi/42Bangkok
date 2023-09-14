#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list    *n_lst;
    t_list    *n_node;

    if (f == NULL || del == NULL)
        return (NULL);
    n_lst = NULL;
    while (lst)
    {
        n_node = ft_lstnew(f(lst->content));
        if (!(n_node))
        {
            ft_lstclear(&n_lst, del);
            return (NULL);
        }
        ft_lstadd_back(&n_lst, n_node);
        lst = lst->next;
    }
    return (n_lst);
}
