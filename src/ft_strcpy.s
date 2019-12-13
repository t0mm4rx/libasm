global _ft_strcpy

_ft_strcpy:	;(char*, const char*) --> char*
	mov rax, 0
	mov rcx, 0

while:
	mov al, [rsi + rcx]
	mov byte [rdi + rcx], al
	cmp al, byte 0
	jz end
	inc rcx
	jmp while

end:
	mov rax, rdi
	ret
