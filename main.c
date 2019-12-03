#include <stdio.h>

int	ft_strlen(char *);
char	*ft_strcpy(char *dst, const char *src);
int	ft_strcmp(const char *s1, const char *s2);
int	ft_write(int, const void*, size_t);
int	ft_read(int, void*, size_t);
char	*ft_strdup(const char*);
int	ft_atoi_base(const char*, const char*);

int main()
{
	printf("==> Tests libasm <==\n");
	ft_write(1, "Hello, world", 12);
}
