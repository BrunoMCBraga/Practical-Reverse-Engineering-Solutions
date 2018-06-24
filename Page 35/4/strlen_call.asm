extern printf

; Define variables in the data section
SECTION .data
	hello:     db "Hello",0
    count_format: db 'Count:%d',10,0
    
    

; Code goes in the text section
SECTION .text
	GLOBAL main

    
main:
    
    push rbp
    mov rbp, rsp
     
    mov rdi, hello
	mov rcx, 0xFFFFFFFFFFFFFFFF
	xor rax,rax
	cld
	repne scasb 
	
	add rcx, 2
	neg rcx
	mov rsi, rcx
    mov rdi, count_format
	mov rax, 0 ; since we dont use xmm
	call printf
    
    mov rsp, rbp
    pop rbp
    ret
