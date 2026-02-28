.text:

global ft_list_sort:

struc List
	.data resq 1
	.next resq 1
endstruc

;void ft_list_sort(t_list **begin_list, int (*cmp)());
ft_list_sort:
	mov rbx, rsi				; save cmp
	mov r12, rdi				; r12 is pointer to pointer to first node
	cmp QWORD [r12], 0
	je .end
	mov r13, [r12]				; r13 is pointer to pointer to second node
	add r13, List.next
	cmp QWORD [r13], 0
	je .end
.loop:
	mov r14, [r12]				; r14 is pointer to first node
	mov r15, [r13]				; r15 is pointer to second node
	mov rdi, [r14 + List.data]	; get data from first node
	mov rsi, [r15 + List.data]	; get data from second node
	push rbx					; save cmp function pointer for later
	call rbx					; call cmp function
	pop rbx						; restore cmp function pointer
	;cmp rax, 0					; lower than 0 means first node is less than second node, so we keep the order
	; cmp is done implicitly as rax is the return value of cmp, so we can just check if it's less than or equal to 0
	jle .next_second			; if cmp returns <= 0, we keep the order and move to next
.swap:
	mov rdi, [r14 + List.data]	; get data from first node
	mov rsi, [r15 + List.data]	; get data from second node
	mov [r14 + List.data], rsi	; set data of first node to second node's data
	mov [r15 + List.data], rdi	; set data of second node to first node's data
.next_second:
	mov r13, r15
	add r13, List.next
	cmp QWORD [r13], 0
	jne .loop
.next_first:
	mov r12, r14				; go to next node for first node
	add r12, List.next
	mov r13, [r12]				; set second node to next node of first node
	add r13, List.next
	cmp QWORD [r13], 0
	jne .loop
.end:
	ret
