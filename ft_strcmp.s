section .text
    global ft_strcmp

ft_strcmp:
    push rbp        ;Guardo el base pointer en el stack
    mov rbp, rsp    ;Igualo el base pointer al stack pointer
    xor rax, rax    ;Inicializo rax a 0 
    xor rcx, rcx
    xor rdx, rdx

loop:
    mov cl, byte [rdi + rax]
    mov dl, byte [rsi + rax]
    cmp cl, dl
    jne exit
    cmp cl, 0
    je exit
    cmp dl, 0
    je exit
    inc rax
    jmp loop
    
exit:
    xor rax, rax
    mov rax, rcx
    sub rax, rdx
    pop rbp         ;Devuelvo el base pointer a su posicion inicial
    ret             ;termina el programa y devuelve los registros de rax y eax