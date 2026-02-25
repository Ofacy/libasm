extern __errno_location;

.text:

global ft_write;

ft_write:
	mov rax, 1				; syscall number for write
	mov rdi, rdi			; file descriptor
	mov rsi, rsi			; buffer
	mov rdx, rdx			; count
	syscall					; call kernel
	cmp rax, 0				; check if syscall returned an error
	jge .end				; if rax >= 0 then return value is number of bytes written
	neg rax					; convert negative error code to positive
	mov rdi, rax			; move error code to rdi for errno
	call __errno_location	; get pointer to errno
	mov [rax], rdi			; set errno to error code
	mov rax, -1				; return -1 on error
	jmp .end				; jump to end
.end:
	ret						; return to caller