.text:

global ft_list_size;

struc List
	.data resq 1
	.next resq 1
endstruc

ft_list_size:
	mov rax, 0			; initialize size counter to 0
.loop:
	cmp rdi, 0
	je .end
	inc rax
	mov rdi, [ rdi + List.next ]
	jmp .loop
.end:
	ret
