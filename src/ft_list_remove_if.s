global _ft_list_remove_if
extern _free

; registers
; r8: void*
; r9: cmp(void*, void*)
; r10: free_el(t_list*)
; r11: list*

; rdi --> void*, rsi --> void*, rdx --> cmp(void*, void*)
_cmp_elem:
	push rdi
	push rsi
	push rax
	push rdx
	push r8
	push r9
	push r10
	push r11
	mov rax, rdx
	call rax
	mov rbx, rax
	pop r11
	pop r10
	pop r9
	pop r8
	pop rdx
	pop rax
	pop rsi
	pop rdi
	mov rax, rbx
	ret

; rdi --> t_list*, rsi --> function free_elem(t_list*)
_free_elem:
	push rax
	push rdi
	push rsi
	push rdx
	push r8
	push r9
	push r10
	push r11
	mov rax, rsi
	call rax
	pop r11
	pop r10
	pop r9
	pop r8
	pop rdx
	pop rsi
	pop rdi
	pop rax
	push rax
	push rdi
	push rdx
	push rsi
	push r8
	push r9
	push r10
	push r11
	call _free
	pop r11
	pop r10
	pop r9
	pop r8
	pop rsi
	pop rdx
	pop rdi
	pop rax
	ret

; rdi --> t_list**, rsi --> void*, rdx --> cmp(), rcx --> free()
_ft_list_remove_if:
	mov r9, rdx			; r9 = &cmp
	mov r10, rcx			; r10 = &free
	mov r8, rsi			; r8 = data_ref
	mov r11, rdi			; r11 = list

	cmp r11, 0			; if (!rdi) return;
	jz _ft_list_remove_if_end

_ft_list_remove_if_while1:
	mov rbx, qword [r11]		; ptr = *list
	cmp rbx, 0			; if (!ptr)
	jz _ft_list_remove_if_end

	mov rdi, r8			; cmp(data_ref, ptr->data)
	mov rsi, qword [rbx]
	mov rdx, r9
	call _cmp_elem

	cmp rax, 0			; if (... != 0)
	jne _ft_go_to_while2		; go to second while

	mov rbx, [r11]
	mov rcx, qword [rbx + 8]	; tmp = ptr->next
	mov [r11], rcx			; *list = tmp

	mov rdi, rbx			; free(ptr)
	mov rsi, r10
	call _free_elem

	jmp _ft_list_remove_if_while1	; loop

_ft_go_to_while2:
	mov rbx, qword [r11]
	mov r11, rbx

_ft_list_remove_if_while2:
	cmp r11, 0			; if (!ptr || !ptr->next) return;
	jz _ft_list_remove_if_end
	cmp qword [r11 + 8], 0
	jz _ft_list_remove_if_end

	mov rdi, r8			; cmp(data_ref, ptr->next->data)
	mov rbx, [r11 + 8]
	mov rsi, qword [rbx]
	mov rdx, r9
	call _cmp_elem

	cmp rax, 0			; if (... == 0)
	je _ft_list_remove_if_remove	; go to remove

	mov r11, [r11 + 8]
	jmp _ft_list_remove_if_while2

_ft_list_remove_if_remove:
	mov rbx, qword [r11 + 8]	; tmp = ptr->next
	mov rcx, qword [rbx + 8]	; tmp2 = ptr->next->next
	mov qword [r11 + 8], rcx	; ptr->next = tmp2

	mov rdi, rbx			; free(tmp)
	mov rsi, r10
	call _free_elem

	jmp _ft_list_remove_if_while2	; go back to second loop

_ft_list_remove_if_end:
	ret
