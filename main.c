#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

extern size_t		ft_strlen(const char *str);
extern char         *ft_strcpy(char *dst, const char *src);
extern int          ft_strcmp(char *s1, char *s2);
extern size_t       ft_write(int fildes, const void *buf, size_t nbyte);
extern size_t       ft_read(int fildes, void *buf, size_t nbyte);

int main ()
{
    char            *str = "Hola que tal estais\0";         
    
    printf("%s = %lu(Length)\n", str, strlen(str));
    printf("%s = %lu(Length)\n", str, ft_strlen(str));
    
    char            *dst =  malloc(ft_strlen(str));
    char            *nul = "";
    int             *ptr = malloc(sizeof(42));

    printf("%s = %s(Copy)\n", str, strcpy(dst, str));
    printf("%s = %s(Copy)\n", str, ft_strcpy(dst, str));

    printf("Copy NULL = %s\n", strcpy(dst, nul));
    printf("Copy NULL = %s\n", ft_strcpy(dst, nul));

    printf("Copy Cast = %s\n", strcpy(dst, (char*)ptr));
    printf("Copy Cast = %s\n", ft_strcpy(dst, (char*)ptr));
    
    printf("%s = %i(Compare Small Source1)\n", str, strcmp("Hola que tal\0", str));
    printf("%s = %i(Compare Small Source1)\n", str, ft_strcmp("Hola que tal\0", str));

    printf("%s = %i(Compare Small Source2)\n", str, strcmp(str, "Hola que tal\0"));
    printf("%s = %i(Compare Small Source2)n", str, ft_strcmp(str, "Hola que tal\0"));

    printf("%s = %i(Compare Equal)\n", str, strcmp(str, "Hola que tal estais\0"));
    printf("%s = %i(Compare Equal)\n", str, ft_strcmp(str, "Hola que tal estais\0"));

    printf("(Syscall_Write) = %lu\n", write(1, "Hola que tal estais\0", ft_strlen(str) + 1));
    printf("(Syscall_Write) = %lu\n", ft_write(1, "Hola que tal estais\0", ft_strlen(str) + 1));

    printf("(Syscall_Write 0 Length) = %lu\n", write(1, "Hola que tal estais\0", 0));
    printf("(Syscall_Write 0 Length) = %lu\n", ft_write(1, "Hola que tal estais\0", 0));

    printf("(Syscall_Write NULL string) = %lu\n", write(1, "", ft_strlen(str) + 1));
    printf("(Syscall_Write NULL string) = %lu\n", ft_write(1, "", ft_strlen(str) + 1));

    int             fd = open("./TestFile.txt", O_RDONLY);

    printf("%s = %lu --> %s(Syscall_Read)\n", str, read(fd, str, 20), str);
    str = "Hola que tal estais\0";
    printf("%s = %lu --> %s(Syscall_Read)\n", str, ft_read(fd, str, 20), str);
    str = "Hola que tal estais\0";
    printf("%s = %lu --> %s(Syscall_Read 0 Length)\n", str, read(fd, str, 0), str);
    str = "Hola que tal estais\0";
    printf("%s = %lu --> %s(Syscall_Read 0 Length)\n", str, ft_read(fd, str, 0), str);
    str = "Hola que tal estais\0";


    return (0);
}