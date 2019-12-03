global _ft_write

;ssize_t	ft_write(int, const void *, size_t)
_ft_write:
	mov rax, 0x2000004
	syscall
	ret
