#include <stdlib.h>
#include <stdio.h>

char *ft_strdup(const char*);

int main()
{
	const char *src = "Ok!";
	char *str = ft_strdup(src);
	printf("%p: %s\n", src, src);
	printf("%p: %s\n", str, str);
	free(str);
	return (0);
}
