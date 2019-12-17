global _ft_list_remove_if

; fixed registers
; r12 --> t_list **list
; r13 --> void *data_ref
; r14 --> cmp()
; r15 --> free()

; void ft_remove_if(t_list**, void*, int *cmp(void*, void*), void *free(t_list*))
_ft_list_remove_if:
	mov r12, rdi
	mov r13, rsi
	mov r14, rdx
	mov r15, r10
	ret
