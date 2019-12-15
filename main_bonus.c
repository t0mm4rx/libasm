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

size_t	ft_list_size(t_list*);
void	ft_list_push_front(t_list**, void*);
int	ft_atoi_base(char*, const char*);

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

	return (0);
}
