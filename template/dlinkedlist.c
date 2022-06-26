#include <stdlib.h>

typedef int (* cmp)(void *, void *);

typedef struct s_linked_list_elem
{
	struct	s_linked_list_elem	*next;
	struct	s_linked_list_elem	*prev;
	void	*value;
}	t_linked_list_elem;

typedef struct s_linked_list
{
	t_linked_list_elem	*head;
	cmp					cmp;
}	t_linked_list;

t_linked_list	*linked_list_new(cmp cmp)
{
	t_linked_list	*tmp;

	tmp = (t_linked_list *)malloc(sizeof(t_linked_list));
	tmp->head = NULL;
	tmp->cmp = cmp;
	return (tmp);
}

void	linked_list_insert(t_linked_list *list, void *value)
{
	t_linked_list_elem	*elem;

	elem = (t_linked_list_elem *)malloc(sizeof(t_linked_list_elem));
	elem->value = value;
	elem->next = list->head;
	elem->prev = NULL;
	list->prev = elem;
	list->head = elem;
}

t_list_elem	*linked_list_search(t_linked_list *list, void *value)
{
	t_linked_list_elem	*tmp;

	tmp = list->head;
	while (tmp)
	{
		if (list->cmp(tmp->value, value) == 0)
			return  (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void	*linked_list_delete(t_linked_list *list, t_linked_list_elem *elem)
{
	if (elem->prev == NULL)
		list->head = elem->next;
	else
		elem->prev->next = elem->next;
	if (elem->next != NULL)
		elem->next->prev = elem->prev;
	free(elem);
}
