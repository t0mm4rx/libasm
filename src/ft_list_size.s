global _ft_list_size

_ft_list_size:
	mov rax, 0

while:
	cmp rdi, 0
	jz end
	inc rax
	mov rdi, [rdi + 8]
	jmp while

end:
	ret
