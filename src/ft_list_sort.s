global _ft_list_sort
global _ft_swap

; fixed registers
; r14 --> a pointer
; r15 --> b pointer
; bubble sort a 0 to end
; b a to end

; void ft_swap(t_list*, t_list*)
_ft_swap:
	push rdi
	push rsi
	mov rbx, [rdi]
	mov rcx, [rsi]
	mov qword [rdi], rcx
	mov qword [rsi], rbx
	pop rsi
	pop rdi
	ret

; void ft_list_sort(t_list**, int (*cmp)(void*, void*))
_ft_list_sort:
	mov r14, [rdi]

_ft_list_sort_while1:
	cmp r14, 0
	jz _ft_list_sort_end
	mov rbx, qword [r14 + 8]
	mov r15, rbx
	call _ft_list_sort_while2
	mov r14, rbx
	jmp _ft_list_sort_while1

_ft_list_sort_while2:
	cmp r15, 0
	jz _ft_list_sort_end
	push rsi
	mov rax, rsi
	mov rdi, qword [r14]
	mov rsi, qword [r15]
	call rax
	pop rsi
	mov rcx, [r15 + 8]
	mov r15, rcx
	jmp _ft_list_sort_while2

_ft_list_sort_end:
	ret
