extern __errno_location
section .text
    global ft_read

ft_read:
    push rbp                            ;Guardo el base pointer en el stack
    mov rbp, rsp                        ;Igualo el base pointer al stack pointer
    sub rsp, 16

    xor rax, rax                        ;Inicializo rax a 0
    xor rcx, rcx
    mov rax, 0                          ;En rax se almacena el id del tipo de interrupcion(syscall) que queremos usar en este caso read = 0
    syscall                             ;Llamamos al syscall, como el syscall usa los mismos estandares de registros para los argumentos no tenemos que tocar nada (rdi, rsi, ...)

    cmp rax, 0                          ;Rax ahora contiene el retorno de syscall, asi que compruebo si es menor que cero, lo que significaria error
    jl send_error

    mov rsp, rbp
    pop rbp                             ;Devuelvo el base pointer a su posicion inicial
    ret                                 ;termina el programa y devuelve los registros de rax y eax

send_error:
    neg rax                             ;Lo paso a positivo
    mov rcx, rax                  ;Lo guardo en otro registro temporalmente porque necesito rax
    call __errno_location WRT ..plt     ;Llamo a la funcion __errno_location que me devolvera en rax la direccion de la variable errno
    mov [rax], rcx                ;Ahora accedo al contenido de errno y guardo dentro el codigo de error parseado
    mov rax, -1                         ;Por ultimo sobrescribimos rax con lo que la funcion read devuelve en caso de error

    mov rsp, rbp
    pop rbp
    ret