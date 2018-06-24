;Prototype
;char* strset( char* s1, int fill);

;Parameters
;s1: The string that you want to fill. 
;fill: The value that you want to fill the string with. 


;Return
;The address of the string, s1.

extern __strlen

; Code goes in the text section
SECTION .text
	GLOBAL __strset

  
__strset:
	push rbp
    mov rbp, rsp
    push rbx
    push r14
    push r15

    mov r15, rdi
    mov rdi, rdi ;string
    call __strlen
    mov rbx, rax


	mov r14, rbx
	dec r14	

	xor rcx, rcx

compare_loop: ; save rcx??????
	mov byte [r15+rcx], sil
	inc rcx
	
	cmp rcx, r14
	jbe compare_loop
	
	mov rax, r15
	
	pop r15
	pop r14
	pop rbx
    mov rsp, rbp
    pop rbp
    ret
