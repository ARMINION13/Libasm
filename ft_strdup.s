extern __errno_location
extern malloc
extern ft_strlen
extern ft_strcpy
section .text
    global ft_strdup

ft_strdup:
    enter 16, 0                         ;Forma facil de hacer --> push rbp | mov rbp, rsp | sub rsp, 16
    xor rax, rax                        

    call ft_strlen WRT ..plt
    
    mov [rbp - 8], rdi
    inc rax
    mov rdi, rax
    
    call malloc WRT ..plt

    cmp rax, 0                          
    jle no_mem_error

    mov rdi, rax
    mov rsi, [rbp - 8]

    call ft_strcpy WRT ..plt

    leave                               ;Forma facil de hacer --> mov rsp, rbp | pop rbp
    ret                                 

no_mem_error:
    call __errno_location WRT ..plt     ;Llamo a la funcion __errno_location que me devolvera en rax la direccion de la variable errno
    mov [rax], 12                       ;Ahora accedo al contenido de errno y guardo dentro el codigo de error ENOMEM
    xor rax, rax                        ;Lo vuelvo a inicializar a 0 porque el puntero es NULL
    
    leave
    ret