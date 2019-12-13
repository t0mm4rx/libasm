global _ft_write

_ft_write:	;(int, void*, int) --> int
	mov rax, 0x2000004 
	syscall
	ret
