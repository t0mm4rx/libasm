global _ft_write

;int	ft_write(int, const void *, size_t)
_ft_write:
	mov rax, 0x2000004
	syscall
	ret
