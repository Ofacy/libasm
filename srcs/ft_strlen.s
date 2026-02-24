.text:

global ft_strlen;

ft_strlen:
	mov rax, 0					; start storing index in return value
loop:
	mov byte DL, [rdi + rax]	; get char
	cmp DL, 0					;
	je end						;
	inc rax						;
	jmp loop					;
end:
	ret							;