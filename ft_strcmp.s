section .text
    global ft_strcmp

ft_strcmp:
    push rbp        ;Guardo el base pointer en el stack
    mov rbp, rsp    ;Igualo el base pointer al stack pointer
    xor rax, rax    ;Inicializo rax a 0 
    xor rbx, rbx
    xor rcx, rcx

loop:
    mov bl, byte [rdi + rax]
    mov cl, byte [rsi + rax]
    cmp bl, cl
    jne exit
    cmp bl, 0
    je exit
    cmp cl, 0
    je exit
    inc rax
    jmp loop
    
exit:
    xor rax, rax
    mov rax, rbx
    sub rax, rcx
    pop rbp         ;Devuelvo el base pointer a su posicion inicial
    ret             ;termina el programa y devuelve los registros de rax y eax