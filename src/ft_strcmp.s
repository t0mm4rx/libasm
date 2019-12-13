global _ft_strcmp

_ft_strcmp:
	mov rax, 0
	mov rcx, 0

while:
	mov al, [rdi]
	mov cl, [rsi]
	cmp al, cl
	jne end
	cmp al, 0
	jz end
	inc rdi
	inc rsi
	jmp while


end:
	sub rax, rcx
	ret
