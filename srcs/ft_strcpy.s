.text:

global ft_strcpy;

ft_strcpy:
	mov rax, rdi		; set dest as return value
.strcpy_loop:
	mov byte DL, [rsi]	; get char
	cmp DL, 0			; is it \0?
	je .end				; if it is then go to end
	mov byte [rdi], DL	; move char to dest buffer
	inc rdi				;
	inc rsi				; increment both buffer pointers
	jmp .strcpy_loop		;
.end:
	mov byte [rdi], 0	; \0 at end of string
	ret					;