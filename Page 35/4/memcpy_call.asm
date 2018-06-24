;void * memcpy ( void * destination, const void * source, size_t num )

;Parameters
;destination
;    Pointer to the destination array where the content is to be copied, type-casted to a pointer of type void*.
;source
;    Pointer to the source of data to be copied, type-casted to a pointer of type const void*.
;num
;    Number of bytes to copy.
;    size_t is an unsigned integral type.


;Return Value
;destination is returned.



extern printf
extern __strlen
extern __memcpy

; Define variables in the data section
SECTION .data
	hello:     db "Hello WORLD!!!",0
    format_string: db 'String original:%s String copy:%s',10,0
    

; Code goes in the text section
SECTION .text
	GLOBAL main

main:
    push rbp
    mov rbp, rsp
    push rbx
    push r12
    push r13

    mov rdi, hello
    call __strlen
    
    mov rbx, rax ; saving string length
    
    lea rdx, [rax+1] ; account for null termination character
    mov rsi, hello
    
    ;Allocating space for string
    sub rsp, rax
    dec rsp
    mov r12, rsp

    mov rdi, rsp
    call __memcpy
    mov r13, rax

    mov rdx, r12
    mov rsi, hello 
    mov rdi, format_string
    mov rax, 0 ; this is really necessary 
    call printf

    add rsp, rbx
    inc rsp

    mov rax, r13
    pop r13
    pop r12
    pop rbx
    mov rsp, rbp
    pop rbp
    ret
