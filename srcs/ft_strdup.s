extern ft_strlen;
extern ft_strcpy;
extern malloc;

.text:

global ft_strdup;

ft_strdup:
	call ft_strlen			; get length of string in rax
	inc rax					; add 1 for null terminator
	mov rdi, rax			; set size for malloc in rdi
	call malloc				; allocate memory for new string, pointer returned in rax
	cmp rax, 0				; check if malloc failed
	je .malloc_failed		; malloc failed, jump to error handling
	mov rdi, rax			; set dest for ft_strcpy to new string
	mov rsi, rdi			; set src for ft_strcpy to original string (passed in rdi)
	call ft_strcpy			; copy string to new memory
.end:
	ret
.malloc_failed:
	mov rax, 0				; return NULL on malloc failure
	jmp .end				; jump to end