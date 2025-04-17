#include "libft.h"
void *ft_strdup_wrapper(void *content)
{
    return ft_strjoin((char *)content, " braint rot"); 
}
int main()
{
	t_list *lst;
	t_list *new_list;
	t_list *node1;
	t_list *node2;
	t_list *node3;

	lst = NULL;
	new_list = NULL;
	node1 = ft_lstnew("bombardino crocodillo");
	node2 = ft_lstnew("um fututo alado");
	node3 = ft_lstnew("qql coisa ai");
	ft_lstadd_back(&lst, node1);
	ft_lstadd_back(&lst, node2);
	ft_lstadd_back(&lst, node3);
	new_list = ft_lstmap(lst, ft_strdup_wrapper, free);
	t_list *newnew_list;
	newnew_list = NULL;
	newnew_list = new_list;
	while(newnew_list)
	{
		printf("%s\n", (char *)newnew_list->content);
		newnew_list = newnew_list->next;
	}
	newnew_list = new_list;
	printf("%s\n", (char *)newnew_list->content);
}