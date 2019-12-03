#include <stdio.h>

int	ft_strlen(char *str);
char	*ft_strcpy(char *dst, const char *src);
int	ft_strcmp(const char *s1, const char *s2);
int	ft_write(int fd, const void *content, size_t length);
int	ft_read(int fd, void *buffer, size_t length);
char	*ft_strdup(const char *src);
int	ft_atoi_base(const char *src, const char *base);

int main()
{
	printf("==> Tests libasm <==\n");
	ft_write(1, "Hello, world", 12);
}
