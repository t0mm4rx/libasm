#include <stdio.h>

int get_base_value(char*, const char*);
int ft_atoi_base(char *, const char *);

int main()
{
	//printf("%d\n", get_base_value("2", "0123456789ABCDEF"));
	printf("%d\n", ft_atoi_base("CCF00", "0123456789ABCDEF"));
	printf("%d\n", ft_atoi_base("0001111011001", "01"));
	printf("%d\n", ft_atoi_base(" -++-10", "01"));
	return (0);
}
