.text:

global ft_list_remove_if;

struc List
	.data resq 1
	.next resq 1
endstruc

ft_list_remove_if:
.loop:
	cmp rdi, 0;
	je .end;
	mov r8, [ rdi ]; store current node in r8
	push rdi					; save current node pointer pointer for later
	push rcx						; save free function pointer
	push rdx						; save cmp function pointer
	mov rdi, [ r8 + List.data ];
	call rdx;						; cmp function call
	pop rdx;						; restore cmp function pointer
	pop rcx;						; restore free function pointer
	pop rdi;

	cmp rax, 0;
	jne .next; ; if cmp returns non-zero, we keep the node and move to next
	; else we remove the node
	mov rax, [ r8 + List.data ];	; get data to free
	mov rdi, rax;					; set data as argument for free
	call [rcx];						; free node data
	mov [ r8 ], rsi;				; bypass the removed node
.next:
	mov rdi, [ r8 + List.next ];
	jmp .loop;
.end:
	ret
