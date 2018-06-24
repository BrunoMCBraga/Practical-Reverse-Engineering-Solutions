extern printf

    
; Code goes in the text section
SECTION .text
	GLOBAL __strlen

    
__strlen:
    
    push rbp
    mov rbp, rsp
    push rbx

    mov rbx, rdi
    mov rdi, rdi
	mov rcx, 0xFFFFFFFFFFFFFFFF
	xor rax,rax
	cld
	repne scasb 
	
	add rcx, 2
	neg rcx
	mov rax, rcx
    
    pop rbx
    mov rsp, rbp
    pop rbp
    ret
