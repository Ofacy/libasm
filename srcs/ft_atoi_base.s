.text:


global ft_atoi_base:

ft_isspace:
	mov rax, 0
	movzx rdi, dil
	cmp rdi, ' '
	je .space
	cmp rdi, 9
	jl .not_space
	cmp rdi, 13
	jg .not_space
.space:
	mov rax, 1
	ret
.not_space:
	ret

; int ft_findcharindex(char *str, char c) (returns -1 if not found)
ft_findcharindex:
	mov rax, 0
	cmp sil, 0
	je .not_found
.loop:
	movzx rdx, byte [rdi + rax]
	cmp dl, sil
	je .end
	cmp byte [rdi + rax], 0
	je .not_found
	inc rax
	jmp .loop
.not_found:
	mov rax, -1
.end:
	ret

; int ft_atoi_base(char *str (rdi), char *base (rsi));
ft_atoi_base:
	mov r12, 0			; base len
	mov r13, 1			; sign
	mov r14, 0			; result
.check_base_content_loop:
	cmp byte [rsi + r12], 0
	je .check_base_len
	push rdi
	movzx rdi, byte [rsi + r12]
	call ft_isspace
	cmp rax, 0
	jne .invalid_base
	push rdi
	push rsi
	lea rdi, [rsi + r12 + 1]
	mov rsi, [rsi + r12]
	call ft_findcharindex
	pop rsi
	pop rdi
	cmp rax, -1
	jne .invalid_base
	cmp rdi, '+'
	je .invalid_base
	cmp rdi, '-'
	je .invalid_base
	pop rdi
	inc r12
	jmp .check_base_content_loop
.check_base_len:
	cmp r12, 1
	jle .end
.skip_whitespace:
	push rdi
	mov rdi, [rdi]
	call ft_isspace
	pop rdi
	cmp rax, 0
	je .check_plus_sign
	inc rdi
	jmp .skip_whitespace
.check_plus_sign:
	cmp byte [rdi], '+'
	jne .check_minus_sign
	inc rdi
	jmp .start_numbers_loop
.check_minus_sign:
	cmp byte [rdi], '-'
	jne .start_numbers_loop
	inc rdi
	mov r13, -1
.start_numbers_loop:
	mov r14, 0
.loop_numbers:
	push rdi
	push rsi
	movzx rdx, byte [rdi]
	lea rdi, [rsi]
	mov rsi, rdx
	call ft_findcharindex
	pop rsi
	pop rdi
	cmp rax, -1
	je .apply_sign
	imul r14, r12
	add r14, rax
	inc rdi
	jmp .loop_numbers
.apply_sign:
	imul r14, r13
.end:
	mov rax, r14
	ret
.invalid_base:
	pop rdi
	jmp .end
