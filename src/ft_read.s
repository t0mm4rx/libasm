global _ft_read

_ft_read:	;(int, void*, int) --> int
	mov rax, 0x2000003
	syscall
	ret
