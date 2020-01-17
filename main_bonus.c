#include <stdio.h>
#include <libc.h>

#define GREEN "\033[32m"
#define RESET "\033[0m"

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
	printf("LIST : ");
	while (node)
	{
		printf("%s --> ", node->data);
		node = node->next;
	}
	printf("NULL\n");
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
int		ft_atoi_base(char*, const char*);
void	ft_swap(t_list*, t_list*);
void	ft_list_sort(t_list**, int (*cmp)(void*, void*));
void	ft_list_remove_if(t_list**, void*, int (*cmp)(void*, void*), void (*free)(t_list*));

void	free_elem(t_list*, void (*free_node)(t_list*));
int		cmp_elem(void*, void*, int(*cmp)(void*, void*));

void print_header(char *str)
{
	printf("\n%s==> %s%s\n", GREEN, str, RESET);
}

int main()
{
	print_header("Tests bonus <==");

	print_header("ft_atoi_base");
	printf("|%d|\n", ft_atoi_base("17", "01234567989ABCDEF"));
	printf("|%d|\n", ft_atoi_base("CF", "01234567989ABCDEF"));
	printf("|%d|\n", ft_atoi_base("1000110", "01"));
	printf("|%d|\n", ft_atoi_base("0", "01"));
	printf("|%d|\n", ft_atoi_base("0", "01 "));
	printf("|%d|\n", ft_atoi_base("  --++- 45102", "012345"));

	print_header("ft_list_size");
	t_list *node = new_list("First !");
	node->next = new_list("Second");
	node->next->next = new_list("Last");
	print_list(node);
	printf("\nLength: %zu\n", ft_list_size(node));
	printf("Length of NULL: %zu\n", ft_list_size(NULL));

	print_header("ft_list_push_front");
	printf("List before push_front :\n");
	print_list(node);
	ft_list_push_front(&node, "Added");
	printf("List after push_front of 'Added' :\n");
	print_list(node);
	t_list *empty = NULL;
	ft_list_push_front(&empty, "Element");
	printf("'Element' added to an NULL list :\n");
	print_list(empty);

	print_header("ft_list_sort");
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
	printf("Source list :\n");
	print_list(list);
	ft_list_sort(&list, &cmp);
	printf("List sorted :\n");
	print_list(list);
	// Segfault test
	ft_list_sort(&empty, NULL);

	print_header("ft_remove_if");
	printf("Source list :\n");
	print_list(list);
	printf("Remove '1':\n");
	ft_list_remove_if(&list, "1", &cmp2, &free_el);
	print_list(list);
	printf("Remove '5':\n");
	ft_list_remove_if(&list, "5", &cmp2, &free_el);
	print_list(list);
	printf("Remove '9':\n");
	ft_list_remove_if(&list, "9", &cmp2, &free_el);
	print_list(list);
	// Segfault test
	ft_list_remove_if(NULL, NULL, NULL, NULL);

	return (0);
}
