;const char * strchr ( const char * str, int character )
;char * strchr (       char * str, int character )
;Parameters:
;str
;    C string.
;character
;    Character to be located. It is passed as its int promotion, but it is internally converted back to char for the comparison. 

;Returns:
; A pointer to the first occurrence of character in str.
; If the character is not found, the function returns a null pointer.

extern printf
extern __strlen

; Define variables in the data section
SECTION .data
	hello:     db "Hello",0
    format_string: db 'String base:0x%x Index:%d Address:0x%x',10,0
    char: db 'e',0
    string_error: db 'Not found.',10,0
    

; Code goes in the text section
SECTION .text
	GLOBAL main

    
main:
    push rbp
    mov rbp, rsp
    
    mov rdi, hello
    call __strlen 
    push rbx
    mov rbx, rax ; saving string length
    
    mov rdi, hello
	mov rcx, rax
	mov rax, [char]
	cld
	repne scasb 
	
	cmp rcx, 0
	jz not_found
	
	sub rbx, rcx 
	dec rbx
	
	lea rcx, [hello + rbx]
	mov rdx, rbx 
	pop rbx
	mov rsi, hello 
	mov rdi, format_string
    call printf
    mov rax, rcx
    jmp end
    
not_found:
    mov rax, 0
    mov rdi, string_error
    call printf

end:
    mov rsp, rbp
    pop rbp
    ret
