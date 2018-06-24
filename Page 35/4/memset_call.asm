;void * memset ( void * ptr, int value, size_t num )

;Parameters

;ptr
;    Pointer to the block of memory to fill.
;value
;    Value to be set. The value is passed as an int, but the function fills the block of memory using the unsigned char conversion of this value.
;num
;    Number of bytes to be set to the value.
;    size_t is an unsigned integral type.

;Return Value
;ptr is returned.


extern printf
extern __memset

%define string_length 0x16

; Define variables in the data section
SECTION .data
	char: db 'A',0
	format_string_result: db "Original:%.20s",10,0 ; not great. It should be snprintf but oh well.
    format_string_original: db "Result:%.20s",10,0

; Code goes in the text section
SECTION .text
	GLOBAL main

    
main:
    push rbp
    mov rbp, rsp
    push rbx
    push r12
    
    
    mov rbx, string_length
    sub rsp, rbx

    mov rsi, rsp
    mov rdi, format_string_original
    mov rax, 0 ; this is really necessary 
    call printf

    mov rdx, rbx
    mov sil, [char]
	mov rdi, rsp        
    call __memset
    mov r13, rax

    mov rsi, rax
    mov rdi, format_string_result
    mov rax, 0 ; this is really necessary 
    call printf

    add rsp, rbx

    mov rax, r13
    pop r12
    pop rbx
    mov rsp, rbp
    pop rbp
    ret
