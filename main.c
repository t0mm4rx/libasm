#include <stdio.h>
#include <string.h>

int	_ft_strlen(char *str);
char	*_ft_strcpy(char *dst, const char *src);
int	_ft_strcmp(const char *s1, const char *s2);
int	_ft_write(int fd, const void *content, size_t length);
int	_ft_read(int fd, void *buffer, size_t length);
char	*_ft_strdup(const char *src);

int main()
{
	printf("==> Tests libasm <==\n");

	_ft_write(1, "Hello, world\n", 13);

	printf("len of 'Hello, world!': %d\n", _ft_strlen("Hello, world!"));

	/*printf("Testing ft_read:\n");
	char buffer[256] = {0};
	_ft_read(0, buffer, 256);
	_ft_write(1, buffer, 256);*/

	printf("%d\n", _ft_strcmp("Ok", "Ok2"));
	printf("%d\n", strcmp("Ok", "Ok2"));
}
