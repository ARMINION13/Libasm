#include <string.h>
#include <stdio.h>

int		ft_strlen(char const *str);

int main ()
{
    char *str = "Hola que tal\0";
    
    printf("%s = %lu\n", str, strlen(str));
    return (0);
}