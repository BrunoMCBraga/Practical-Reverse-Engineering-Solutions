;Prototype
;char* strset( char* s1, int fill);

;Parameters
;s1: The string that you want to fill. 
;fill: The value that you want to fill the string with. 


;Return
;The address of the string, s1.


extern printf
extern __strset

%define string_length 0x16

; Define variables in the data section
SECTION .data
	format_string: db "%.20s",10,0 ; not great. It should be snprintf but oh well.
	string: db "Hello1",0
	char: db "#",0
	err_string: db "One of the strings is invalid",10,0
	result_format_string: db "Result:%s",10,0
	original_format_string: db "Before:%s",10,0

; Code goes in the text section
SECTION .text
	GLOBAL main

main:

	push rbp
    mov rbp, rsp
    push rbx
    
    mov rsi, string
    mov rdi, original_format_string
	mov rax, 0
	call printf

    mov byte sil, [char] 
    mov rdi, string
    call __strset

    mov rsi, rax
    mov rdi, result_format_string
	mov rax, 0
	call printf

end_main:
	pop rbx
	mov rsp, rbp
	pop rbp
	ret