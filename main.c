#include <stdio.h>
#include <string.h>
#include <libc.h>
#include <unistd.h>

int	ft_strlen(char *str); //done
char	*ft_strcpy(char *dst, const char *src);
int	ft_strcmp(const char *s1, const char *s2); //done
int	ft_write(int fd, const void *content, size_t length); //done
int	ft_read(int fd, void *buffer, size_t length); //done
char	*ft_strdup(const char *src);

int main()
{
	printf("==> Tests libasm <==\n");

	printf("\n** Testing ft_write:\n");
	ft_write(1, "Hello, world\n", 13);
	ft_write(1, "", 1);
	ft_write(1, NULL, 0);
	ft_write(1, "I love Assembly\n", 3);
	ft_write(1, "\n", 1);

	printf("\n** Testing ft_strlen:\n");
	printf("'hello': (%d, %lu)\n", ft_strlen("hello"), strlen("hello"));
	printf("'': (%d, %lu)\n", ft_strlen(""), strlen(""));
	printf("'Ok !\\0Hey !': (%d, %lu)\n", ft_strlen("Ok !\0Hey !"), strlen("Ok !\0Hey !"));

	printf("\n** Testing ft_strcmp:\n");
	printf("'', '': (%d, %d)\n", ft_strcmp("", ""), strcmp("", ""));
	printf("'Ok', 'Okok': (%d, %d)\n", ft_strcmp("Ok", "Okok"), strcmp("Ok", "Okok"));
	printf("'abc', 'abd': (%d, %d)\n", ft_strcmp("abc", "abd"), strcmp("abc", "abd"));

	printf("\n** Testing ft_strcpy:\n");
	const char *src = "Hello world!";
	char *dest = calloc(20, sizeof(char));
	ft_strcpy(dest, src);
	printf("%s\n", dest);
	strcpy(dest, src);
	printf("%s\n", dest);
	free(dest);

	printf("\n** Testing ft_strdup:\n");
	char *src2 = "Hello world!";
	char *res = ft_strdup(src2);
	printf("|%p %p %s %lu|\n", src2, res, res, strlen(res));
	free(res);
	res = strdup(src2);
	printf("|%p %p %s %lu|\n", src2, res, res, strlen(res));
	free(res);

	printf("\n** Testing ft_read:\n");
	char buffer[256] = {0};
	ft_read(0, buffer, 256);
	ft_write(1, buffer, 256);

}
