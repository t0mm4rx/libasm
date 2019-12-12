global _ft_strlen

_ft_strlen:
	mov rcx,0
	call _loop
	mov rax,rcx

_loop:
	inc rcx
	inc rdi
	mov cl,[rdi]
	cmp cl,0
	jne _loop
