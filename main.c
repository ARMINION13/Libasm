#include <string.h>
#include <stdio.h>
#include <stdlib.h>

extern size_t		ft_strlen(const char *str);
extern char         *ft_strcpy(char *dst, const char *src);
extern int          ft_strcmp(char *s1, char *s2);

int main ()
{
    char            *str = "Hola que tal estais\0";
    
    printf("%s = %lu\n", str, strlen(str));
    printf("%s = %li\n", str, ft_strlen(str));
    
    char   *dst =  malloc(ft_strlen(str));
    char   *nul = "";
    int    *ptr = malloc(sizeof(42));

    printf("%s = %s\n", str, strcpy(dst, str));
    printf("%s = %s\n", str, ft_strcpy(dst, str));

    printf("%s = %s\n", "NULL", strcpy(dst, nul));
    printf("%s = %s\n", "NULL", ft_strcpy(dst, nul));

    printf("%s = %s\n", "Cast", strcpy(dst, (char*)ptr));
    printf("%s = %s\n", "Cast", ft_strcpy(dst, (char*)ptr));
    
    printf("%s = %i\n", str, strcmp("Hola que tal\0", str));
    printf("%s = %i\n", str, ft_strcmp("Hola que tal\0", str));

    printf("%s = %i\n", str, strcmp(str, "Hola que tal\0"));
    printf("%s = %i\n", str, ft_strcmp(str, "Hola que tal\0"));

    printf("%s = %i\n", str, strcmp(str, "Hola que tal estais\0"));
    printf("%s = %i\n", str, ft_strcmp(str, "Hola que tal estais\0"));

    return (0);
}