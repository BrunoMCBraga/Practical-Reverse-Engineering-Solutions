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


extern printf
extern __strcmp

%define string_length 0x16

; Define variables in the data section
SECTION .data
	format_string: db "%.20s",10,0 ; not great. It should be snprintf but oh well.
	string1: db "Hello1",0
	string2: db "Hell0",0
	err_string: db "One of the strings is invalid",10,0
	strings_match: db "Strings are equal!",10,0
	str1_is_greater: db "String1 is greater than 2.",10,0
   	str2_is_greater: db "String2 is greater than 1.",10,0

; Code goes in the text section
SECTION .text
	GLOBAL main

  
main:

	push rbp
    mov rbp, rsp
    
    mov rdi, string1
    mov rsi, string2
    call __strcmp

    cmp rax, 0
    jl string1_less_than_string2
    jg  string2_less_than_string1
    
    mov rdi, strings_match
    mov rax, 0
	call printf
	jmp end_main

string1_less_than_string2:
	mov rdi, str2_is_greater
	mov rax, 0
	call printf
	jmp end_main

string2_less_than_string1:
	mov rdi, str1_is_greater
	mov rax, 0
	call printf
	jmp end_main

end_main:
	mov rsp, rbp
	pop rbp
	ret