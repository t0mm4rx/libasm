global _ft_list_remove_if
extern _free

; fixed registers
; r12 --> t_list **list
; r13 --> void *data_ref
; r14 --> cmp()
; r15 --> free()
; r8 --> ptr

; void ft_remove_if(t_list**, void*, int *cmp(void*, void*), void *free(t_list*))
_ft_list_remove_if:
	mov r12, rdi
	mov r13, rsi
	mov r14, rdx
	mov r15, r10
	cmp r12, 0
	jz _ft_list_remove_if_end
	cmp r14, 0
	jz _ft_list_remove_if_end
	;cmp r15, 0
	;jz _ft_list_remove_if_end
	mov r8, [r12]
	jmp _ft_remove_if_while1

_ft_list_remove_if_end:
	ret

_ft_remove_if_while1:
	cmp r8, 0						; if (!ptr)
	jz _ft_list_remove_if_end		; return
	mov rdi, qword[r8]				; 
	mov rsi, r13					;
	call _ft_call_cmp
	cmp rax, 0						; if (a != 0)
	jne _ft_list_remove_if_while2	; go to while 2
	mov r9, qword [r8 + 8]			; temp = ptr->next
	mov rdi, r8						;
	; call _ft_call_free
	mov r8, r9						; ptr = temp
	mov [r12], r9					; *list = temp
	jmp _ft_remove_if_while1		; go to top of while

_ft_list_remove_if_while2:
	cmp r8, 0
	jz _ft_list_remove_if_end
	cmp qword[r8 + 8], 0
	jz _ft_list_remove_if_end
	mov r9, [r8 + 8]
	mov rdi, qword [r9]
	mov rsi, r13
	call _ft_call_cmp
	cmp rax, 0
	jne _ft_list_remove_if_while2_end
	mov rbx, qword [r9 + 8]
	mov qword [r8 + 8], rbx
	mov r8, rbx
	; mov rdi, r9
	; call _ft_call_cfree
	mov rdi, r9
	; call _ft_call_free
	jmp _ft_list_remove_if_while2

_ft_list_remove_if_while2_end:
	mov r8, r9
	jmp _ft_list_remove_if_while2

_ft_call_free:
	push r8							; save registers
	push r9							;
	push r10						;
	push r12						;
	push r13						;
	push r14						;
	push r15						;
	call _free
	pop r15							; restore registers
	pop r14							;
	pop r13							;
	pop r12							;
	pop r10							;
	pop r9							;
	pop r8							;
	ret

_ft_call_cfree:
	push r8							; save registers
	push r9							;
	push r10						;
	push r12						;
	push r13						;
	push r14						;
	push r15						;
	mov rax, r15
	call rax
	pop r15							; restore registers
	pop r14							;
	pop r13							;
	pop r12							;
	pop r10							;
	pop r9							;
	pop r8							;
	ret

_ft_call_cmp:
	push r8							; save registers
	push r9							;
	push r10						;
	push r12						;
	push r13						;
	push r14						;
	push r15						;
	;mov rdi, qword[r8]				; 
	;mov rsi, r13					;
	mov rax, r14					;
	call rax						; int a = cmp(ptr->data, data_ref)
	pop r15							; restore registers
	pop r14							;
	pop r13							;
	pop r12							;
	pop r10							;
	pop r9							;
	pop r8							;
	ret
