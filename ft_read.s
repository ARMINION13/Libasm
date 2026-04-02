section .text
    global ft_read

ft_read:
    push rbp        ;Guardo el base pointer en el stack
    mov rbp, rsp    ;Igualo el base pointer al stack pointer
    xor rax, rax    ;Inicializo rax a 0
    mov rax, 0      ;En rax se almacena el id del tipo de interrupcion(syscall) que queremos usar en este caso read = 0
    syscall         ;Llamamos al syscall, como el syscall usa los mismos estandares de registros para los argumentos no tenemos que tocar nada (rdi, rsi, ...)
    pop rbp         ;Devuelvo el base pointer a su posicion inicial
    ret             ;termina el programa y devuelve los registros de rax y eax