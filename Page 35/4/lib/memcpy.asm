;void * memcpy ( void * destination, const void * source, size_t num )

;Parameters
;destination
;    Pointer to the destination array where the content is to be copied, type-casted to a pointer of type void*.
;source
;    Pointer to the source of data to be copied, type-casted to a pointer of type const void*.
;num
;    Number of bytes to copy.
;    size_t is an unsigned integral type.


;Return Value
;destination is returned.

; Code goes in the text section
SECTION .text
	GLOBAL __memcpy

    
__memcpy:
    
    push rbp
    mov rbp, rsp
    push rbx
    
    mov rbx, rdi
	mov rcx, rdx
	cld
	repne movsb
    
    mov rax, rbx
    
    pop rbx
    mov rsp, rbp
    pop rbp
    ret
