section .text
    global ft_strlen

ft_strlen:
    push rbp        ;Guardo el base pointer en el stack
    mov rbp, rsp    ;Igualo el base pointer al stack pointer
    xor rax, rax    ;Inicializo rax a 0 

loop:
    cmp byte [rdi + rax], 0
    je  exit
    inc rax
    jmp loop
    
exit:
    pop rbp         ;Devuelvo el base pointer a su posicion inicial
    ret             ;termina el programa y devuelve los registros de rax y eax