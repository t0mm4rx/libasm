global _ft_list_push_front
extern _malloc

; fixed registers
; rdi --> t_list**
; rsi --> void*

; t_list *ft_create_elem(void *data)
_ft_create_elem:
	push rdi
	mov rdi, 16
	call _malloc
	pop rdi
	mov qword [rax], qword rdi
	mov qword [rax + 8], qword 0
	ret

_ft_list_push_front:
	mov bl, [rdi]
	cmp bl, 0
	jz _ft_list_push_front_empty
	jmp _ft_list_push_front_existing

; void ft_list_push_front(t_list**, void*)
_ft_list_push_front_empty:
	push rdi
	mov rdi, rsi
	call _ft_create_elem
	pop rdi
	mov [rdi], rax
	ret

_ft_list_push_front_existing:
	push rdi
	mov rdi, rsi
	call _ft_create_elem
	pop rdi
	mov rbx, [rdi]
	mov qword [rax + 8], rbx
	mov [rdi], rax
	ret

