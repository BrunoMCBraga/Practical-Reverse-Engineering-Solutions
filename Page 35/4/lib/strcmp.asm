;Prototype
;int strcmp(const char *str1, const char *str2)

;Parameters
;str1 − This is the first string to be compared.
;str2 − This is the second string to be compared.

;Return
;This function return values that are as follows −
;if Return value < 0 then it indicates str1 is less than str2.
;if Return value > 0 then it indicates str2 is less than str1.
;if Return value = 0 then it indicates str1 is equal to str2.


extern __strlen

; Code goes in the text section
SECTION .text
	GLOBAL __strcmp

__strcmp:
    push rbp
    mov rbp, rsp
    push rbx
    push r12
    push r13
    push r14
    push r15

    mov r15, rdi
    mov rdi, rdi ;string1
    call __strlen
    mov rbx, rax

    mov rdi, rsi; string2
	call __strlen
    mov r12, rax


    cmp rbx, 0
    je string1_empty

    cmp r12, 0
	je string2_empty

	jmp pre_loop

string1_empty:
	cmp r12,0 
	je strings_empty
	mov rax, 0xFFFFFFFFFFFFFFFF
	jmp end_strcmp

string2_empty:
	cmp rbx,0 
	je strings_empty
	mov rax, 0x1
	jmp end_strcmp

strings_empty:
	mov rax, 0
	jmp end_strcmp

pre_loop:
    xor rcx, rcx
    xor r13, r13

    cmp rbx, r12
    jb str1_shorter
    ja str2_shorter
  	jmp strings_equal_size

str1_shorter:
	mov r14, rbx
    dec r14
    jmp compare_loop

str2_shorter:
	mov r14, r12
	dec r14
    jmp compare_loop

strings_equal_size:
	mov r14, rbx
    dec r14	

compare_loop: ; i am comparing byte by byte. A better approach would be checking the number of dwords of quadword and compare those
	mov byte r13b, [r15+rcx]
	cmp byte r13b, [rsi+rcx]
	jb str1_less_than_str2
	ja str2_less_than_str1
	inc rcx
	
	cmp rcx, r14
	jbe compare_loop
	
	mov rax, 0
	jmp end_strcmp
	 

str1_less_than_str2:
	mov rax, 0xFFFFFFFFFFFFFFFF
	jmp end_strcmp

str2_less_than_str1:
	mov rax, 0x1
	jmp end_strcmp

invalid_string:
	mov rax, 0
	jmp end_strcmp

end_strcmp:
	pop r15
	pop r14
    pop r13
    pop r12
    pop rbx
    mov rsp, rbp
    pop rbp
    ret