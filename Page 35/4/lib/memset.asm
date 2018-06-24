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


SECTION .text
	GLOBAL __memset

    
__memset:
    
    push rbp
    mov rbp, rsp
    push rbx

    mov rbx, rdi
    
    mov rcx, rdx
	mov byte al, sil
	cld
	rep stosb
    
    mov rax, rbx
    
    pop rbx
    mov rsp, rbp
    pop rbp
    ret