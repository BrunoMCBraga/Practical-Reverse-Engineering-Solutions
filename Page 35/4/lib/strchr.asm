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

extern __strlen

; Code goes in the text section
SECTION .text
	GLOBAL strchr

__strchr:
    push rbp
    mov rbp, rsp
    push rbx
    push r14
    
    mov rbx, rdi
    mov rdi, rdi
    call __strlen 
    mov r14, rax ; saving string length
    
    mov rdi, rbx
	mov rcx, r14
	mov byte al, sil
	cld
	repne scasb 
	
	cmp rcx, 0
	jz not_found
	
	sub r14, rcx 
	lea rax, [r14 + rbx]

    mov rax, rcx
    jmp end
    
not_found:
    mov rax, 0

end:
	pop r14
	pop rbx
    mov rsp, rbp
    pop rbp
    ret
