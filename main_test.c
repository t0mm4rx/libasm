#include <stdlib.h>
#include <stdio.h>

typedef struct	s_list
{
	void		*data;
	struct s_list	*next;
}		t_list;

t_list	*ft_create_elem(void *data);

int	main()
{
	t_list *elem = ft_create_elem("Test");
	printf("|%s %p|\n", elem->data, elem->next);
	return (0);
}
