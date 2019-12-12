global _ft_strcmp

_ft_strcmp:
	mov rax, 0
	mov rcx, 0

while:
	mov al, [rdi]
	mov cl, [rsi]
	cmp al, cl
	jne end

end:
	sub al, cl
	ret
