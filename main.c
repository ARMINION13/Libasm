#include <string.h>
#include <stdio.h>

extern size_t		ft_strlen(char const *str);

int main ()
{
    char *str = "Hola que tal estais\0";
    
    printf("%s = %lu\n", str, strlen(str));
    printf("%s = %li\n", str, ft_strlen(str));
    return (0);
}