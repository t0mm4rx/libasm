#include <stdio.h>
#include <string.h>
#include <libc.h>
#include <unistd.h>

#define GREEN "\033[32m"
#define RESET "\033[0m"

int		ft_strlen(char *str);
char	*ft_strcpy(char *dst, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_write(int fd, const void *content, size_t length);
int		ft_read(int fd, void *buffer, size_t length);
char	*ft_strdup(const char *src);

void print_header(char *str)
{
	printf("\n%s==> %s%s\n", GREEN, str, RESET);
}

int main()
{
	print_header("libasm <==\n");

	print_header("ft_write");
	ft_write(1, "Hello, world!\n", 14);
	ft_write(1, "", 1);
	ft_write(1, NULL, 0);
	ft_write(1, "I love Assembly\n", 3);
	ft_write(1, "\n", 1);

	print_header("ft_strlen");
	printf("'hello': (%d, %lu)\n", ft_strlen("hello"), strlen("hello"));
	printf("'': (%d, %lu)\n", ft_strlen(""), strlen(""));
	printf("'Ok !\\0Hey !': (%d, %lu)\n", ft_strlen("Ok !\0Hey !"), strlen("Ok !\0Hey !"));

	print_header("ft_strcmp");
	printf("'', '': (%d, %d)\n", ft_strcmp("", ""), strcmp("", ""));
	printf("'Ok', 'Okok': (%d, %d)\n", ft_strcmp("Ok", "Okok"), strcmp("Ok", "Okok"));
	printf("'abc', 'abd': (%d, %d)\n", ft_strcmp("abc", "abd"), strcmp("abc", "abd"));
	printf("'abd', 'abc': (%d, %d)\n", ft_strcmp("abd", "abc"), strcmp("abd", "abc"));

	print_header("ft_strcpy");
	const char *src = "Hello world!";
	printf("Source = %p %s\n", src, src);
	char *dest = calloc(20, sizeof(char));
	ft_strcpy(dest, src);
	printf("%p = %s\n", dest, dest);
	strcpy(dest, src);
	printf("%p = %s\n", dest, dest);
	free(dest);

	print_header("ft_strdup");
	char *src2 = "Hello world!";
	char *res = ft_strdup(src2);
	printf("Source = %p %s\n", src2, src2);
	printf("|%p %s %lu|\n", res, res, strlen(res));
	free(res);
	res = strdup(src2);
	printf("|%p %s %lu|\n", res, res, strlen(res));
	free(res);

	print_header("ft_read");
	char buffer[256] = {0};
	ft_read(0, buffer, 256);
	ft_write(1, buffer, 256);

}
