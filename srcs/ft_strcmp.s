.text:

global ft_strcmp;

ft_strcmp:
	mov rdx, 0					; start storing index in return value
.loop:
	mov al, [rdi + rdx]			; get char from s1
	mov bl, [rsi + rdx]			; get char from s2
	cmp al, bl					; compare chars
	jne .end					; if they are different then go to end
	cmp al, 0					; if char is \0 then we are at end of both strings
	je .end						;
	inc rdx						;
	jmp .loop					;
.end:
	mov al, [rdi + rdx]			; get char from s1
	mov bl, [rsi + rdx]			; get char from s2
	movzx rax, al				; zero-extend char to return value
	movzx rbx, bl				; zero-extend char to return value
	sub rax, rbx				; return difference between
	ret							;