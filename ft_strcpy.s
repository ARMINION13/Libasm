section .text
    global ft_strcpy

ft_strcpy:
    push rbp        ;Guardo el base pointer en el stack
    mov rbp, rsp    ;Igualo el base pointer al stack pointer
    
    xor rax, rax    ;Inicializo rax a 0 
    xor rcx, rcx

loop:
    mov cl, byte [rsi + rax]
    mov byte [rdi + rax], cl
    cmp cl, 0
    je  exit
    inc rax
    jmp loop
    
exit:
    mov rax, rdi
    pop rbp         ;Devuelvo el base pointer a su posicion inicial
    ret             ;termina el programa y devuelve los registros de rax y eax