#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h> //contiene la variable global errno para manejo de errores

extern size_t		ft_strlen(const char *str);
extern char         *ft_strcpy(char *dst, const char *src);
extern int          ft_strcmp(char *s1, char *s2);
extern size_t       ft_write(int fildes, const void *buf, size_t nbyte);
extern size_t       ft_read(int fildes, void *buf, size_t nbyte);
extern char         *ft_strdup(const char *s);

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
    printf("%s = %i(Compare Small Source2)\n", str, ft_strcmp(str, "Hola que tal\0"));

    printf("%s = %i(Compare Equal)\n", str, strcmp(str, "Hola que tal estais\0"));
    printf("%s = %i(Compare Equal)\n", str, ft_strcmp(str, "Hola que tal estais\0"));

    printf("(Syscall_Write) = %li\n", write(1, "Hola que tal estais\0", ft_strlen(str) + 1));
    printf("(Syscall_Write) = %li\n", ft_write(1, "Hola que tal estais\0", ft_strlen(str) + 1));

    printf("(Syscall_Write 0 Length) = %li\n", write(1, "Hola que tal estais\0", 0));
    printf("(Syscall_Write 0 Length) = %li\n", ft_write(1, "Hola que tal estais\0", 0));

    printf("(Syscall_Write NULL string) = %li\n", write(1, "", ft_strlen(str) + 1));
    printf("(Syscall_Write NULL string) = %li\n", ft_write(1, "", ft_strlen(str) + 1));
    
    printf("(Syscall_Write FD error) = %li\n", write(-1, "Hola que tal estais\0", ft_strlen(str) + 1));
    printf("Error detectado: %d\n", errno);
    printf("(Syscall_Write FD error) = %li\n", ft_write(-1, "Hola que tal estais\0", ft_strlen(str) + 1));
    printf("Error detectado: %d\n", errno);

    int             fd1 = open("TestFile.txt", O_RDONLY);
    int             fd2 = open("TestFile.txt", O_RDONLY);

    printf("%li = %s(Syscall_Read)\n", read(fd1, dst, 20), dst);
    printf("%li = %s(Syscall_Read)\n", read(fd2, dst, 20), dst);
    ft_strcpy(dst, str);

    printf("%li = %s(Syscall_Read 0 Length)\n", read(fd1, dst, 20), dst);
    printf("%li = %s(Syscall_Read 0 Length)\n", read(fd2, dst, 20), dst);

    printf("%li = %s(Syscall_Read)\n", read(-1, dst, 20), dst);
    printf("Error detectado: %d\n", errno);
    printf("%li = %s(Syscall_Read)\n", read(-1, dst, 20), dst);
    printf("Error detectado: %d\n", errno);

    char *dup1;
    char *dup2;
    int error1;
    int error2;
    
    dup1 = strdup(str);
    dup2 = ft_strdup(str);
    printf("%s(strdup) = %s(ft_strdup)\n", dup1, dup2);

    dup1 = strdup("");
    error1 = errno;
    dup2 = ft_strdup("");
    error2 = errno;
    printf("%s(strdup) = %s(ft_strdup)\n", dup1, dup2);
    printf("Error detectado: %d (strdup), %d (ft_strdup)\n", error1, error2);


    return (0);
}