global _ft_strlen

_ft_strlen:	;(const char*) --> int
	mov rcx, 0

while:
	cmp byte [rdi + rcx], byte 0
	jz end
	inc rcx
	jmp while

end:
	mov rax, rcx
	ret
