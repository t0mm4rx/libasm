#include <stdio.h>
#include <libc.h>

typedef struct		s_list
{
	void		*data;
	struct s_list 	*next;
}			t_list;

t_list	*new_list(void *data)
{
	t_list *res;

	res = calloc(1, sizeof(t_list));
	res->data = data;
	res->next = NULL;
	return (res);
}

void	print_list(t_list *node)
{
	while (node)
	{
		printf("%s --> ", node->data);
		node = node->next;
	}
	printf("NULL");
}

int	cmp(void *a, void *b)
{
	if (!a || !b)
		return (0);
	return (strcmp(a, b));
}

int	cmp2(void *a, void *b)
{
	return (((char*)a)[0] != ((char*)b)[0]);
}

void	free_el(t_list *el)
{
	(void)el;
}

size_t	ft_list_size(t_list*);
void	ft_list_push_front(t_list**, void*);
int	ft_atoi_base(char*, const char*);
void	ft_swap(t_list*, t_list*);
void	ft_list_sort(t_list**, int (*cmp)(void*, void*));
void	ft_list_remove_if(t_list**, void*, int (*cmp)(void*, void*), void (*free)(t_list*));

void	free_elem(t_list*, void (*free_node)(t_list*));
int	cmp_elem(void*, void*, int(*cmp)(void*, void*));

int main()
{
	printf("Tests bonus\n");

	printf("\n** Testing ft_atoi_base:\n");
	printf("|%d|\n", ft_atoi_base("17", "01234567989ABCDEF"));
	printf("|%d|\n", ft_atoi_base("CF", "01234567989ABCDEF"));
	printf("|%d|\n", ft_atoi_base("1000110", "01"));
	printf("|%d|\n", ft_atoi_base("0", "01"));
	printf("|%d|\n", ft_atoi_base("0", "01 "));
	printf("|%d|\n", ft_atoi_base("  --++- 45102", "012345"));

	printf("\n** Testing ft_list_size:\n");
	t_list *node = new_list("First !");
	node->next = new_list("Second");
	node->next->next = new_list("Last");
	print_list(node);
	printf("\nLength: %zu\n", ft_list_size(node));
	printf("Length of empty list: %zu\n", ft_list_size(NULL));

	printf("\n** Testing ft_list_push_front:\n");
	ft_list_push_front(&node, "Added");
	print_list(node);
	t_list *empty = NULL;
	ft_list_push_front(&empty, "Added to empty list");
	printf("\n");
	print_list(empty);
	printf("\n");

	printf("\n** Testing ft_list_sort:\n");
	t_list *list;
	ft_list_push_front(&list, "5");
	ft_list_push_front(&list, "3");
	ft_list_push_front(&list, "7");
	ft_list_push_front(&list, "7");
	ft_list_push_front(&list, "1");
	ft_list_push_front(&list, "1");
	ft_list_push_front(&list, "7");
	ft_list_push_front(&list, "9");
	ft_list_push_front(&list, "8");
	print_list(list);
	printf("\n");
	ft_list_sort(&list, &cmp);
	//ft_swap(list, list->next);
	print_list(list);
	printf("\n");
	ft_list_sort(&empty, NULL);

	printf("\n** Testing remove if:\n");
	print_list(list);
	printf("\n\nRemove '1':\n");
	ft_list_remove_if(NULL, NULL, NULL, NULL);
	ft_list_remove_if(&list, "1", &cmp2, &free_el);
	print_list(list);
	printf("\n\nRemove '5':\n");
	ft_list_remove_if(&list, "5", &cmp2, &free_el);
	print_list(list);
	printf("\n\nRemove '9':\n");
	ft_list_remove_if(&list, "9", &cmp2, &free_el);
	print_list(list);
	//t_list *el = new_list("ok");
	//free_elem(el, &free_el);

	return (0);
}
