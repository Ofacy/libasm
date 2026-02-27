.text:

extern malloc;

global ft_list_push_front;

struc List
	.data resq 1
	.next resq 1
endstruc

ft_list_push_front:
	push rdi
	push rsi
	mov rdi, 16	
	call malloc
	pop rsi
	pop rdi
	cmp rax, 0
	je .malloc_failed
	mov [ rax + List.data ], rsi
	mov rsi, [ rdi ]
	mov [ rax + List.next ], rsi
	mov [ rdi ], rax

.end:
	ret


.malloc_failed:
	mov rax, 0
	jmp .end