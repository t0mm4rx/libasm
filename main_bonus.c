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

size_t	ft_list_size(t_list *list);
int	get_base_value(char c, char *base);

int main()
{
	printf("Tests bonus\n");

	printf("\n** Testing ft_atoi_base:\n");
	printf("|%d|\n", get_base_value('3', "01234567989ABCDEF"));

	t_list *node = new_list("First !");
	node->next = new_list("Second");
	node->next->next = new_list("Last");

	print_list(node);
	printf("\n\n** Testing ft_list_size:\n");
	printf("Length: %zu\n", ft_list_size(node));
	printf("Length of empty list: %zu\n", ft_list_size(NULL));


	return (0);
}
