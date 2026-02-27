.text:

extern free;

global ft_list_remove_if;

struc List
	.data resq 1
	.next resq 1
endstruc

ft_list_remove_if:
.loop:
	mov r13, [ rdi ]; store current node ptr in r8
	cmp r13, 0;
	je .end;
	push rdi					; save current node pointer pointer for later
	push rcx						; save free function pointer
	push rdx						; save cmp function pointer
	push rsi;
	mov rdi, [ r13 + List.data ];
	call rdx;						; cmp function call
	pop rsi;
	pop rdx;						; restore cmp function pointer
	pop rcx;						; restore free function pointer
	pop rdi;

	cmp rax, 0;
	jne .next; ; if cmp returns non-zero, we keep the node and move to next
	; else we remove the node

.save_next_ptr:
	mov r12, [r13 + List.next];
.free_data:
	push rdi;
	push rcx;
	push rsi;
	push rdx;
	mov rdi, [ r13 + List.data ];		; set data as argument for free
	call rcx;						; free node data
.free_node:
	mov rdi, r13;					; set node ptr as argument for free
	call free;						; free node
	pop rdx;
	pop rsi;
	pop rcx;
	pop rdi;
	mov [rdi], r12;				; bypass the removed node
	jmp .loop;
.next:
	mov rdi, [rdi];
	add rdi, List.next;
	jmp .loop;
.end:
	ret
