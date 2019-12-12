global _ft_strcmp

_ft_strcmp:

while:
	mov al, [rdi]
	mov cl, [rsi]
	cmp byte al, byte cl
	jne end
	inc rdi
	inc rsi
	jmp while

end:
	sub cl, al
	ret

