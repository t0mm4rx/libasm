global _ft_strdup
extern _malloc
extern _ft_strlen
extern _ft_strcpy

_ft_strdup:	;(const char*) --> char*
	;mov r14, rdi
	push rdi
	call _ft_strlen
	mov rdi, rax
	inc rdi
	call _malloc
	mov rdi, rax
	;mov rsi, r14
	pop rsi
	call _ft_strcpy
	ret

