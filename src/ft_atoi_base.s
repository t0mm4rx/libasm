global _ft_atoi_base
global _get_base_value

; fixed registers
; r15 --> total result
; r14 --> length of the base
; r13 --> sign
; rdi --> number in base
; rsi --> base

_ft_atoi_base:
	mov r15, 0
	mov r14, 0
	mov r13, 1
	call _ft_strlen_base
	cmp rax, 1
	jle _ft_atoi_base_error
	mov r14, rax
	call _check_base
	cmp rax, 0
	jz _ft_atoi_base_error
	call _get_sign

_ft_atoi_base_while:
	cmp [rdi], byte 0
	jz _ft_atoi_base_end
	imul r15, r14
	call _get_base_value
	cmp rax, -1
	je _ft_atoi_base_error
	add r15, rax
	inc rdi
	jmp _ft_atoi_base_while

_ft_atoi_base_end:
	mov rax, r15
	imul rax, r13
	ret

_ft_atoi_base_error:
	mov rax, 0
	ret

_get_base_value:
	mov rax, 0
	mov rcx, 0

_get_base_value_while:
	push rcx
	mov bl, [rsi + rcx]
	mov cl, [rdi]
	cmp bl, byte 0
	jz _get_base_value_error
	cmp bl, cl
	je _get_base_value_end
	pop rcx
	inc rcx
	jmp _get_base_value_while

_get_base_value_end:
	pop rcx
	mov rax, rcx
	ret

_get_base_value_error:
	pop rcx
	mov rax, -1
	ret

_ft_strlen_base:
	push rcx
	mov rcx, 0

_ft_strlen_base_while:
	mov bl, [rsi + rcx]
	cmp bl, byte 0
	jz _ft_strlen_base_end
	inc rcx
	jmp _ft_strlen_base_while

_ft_strlen_base_end:
	mov rax, rcx
	pop rcx
	ret

_check_base:
	push rcx
	mov rcx, 0

_check_base_while:
	mov bl, [rsi + rcx]
	cmp bl, byte 0
	jz _check_base_success
	cmp bl, byte 32
	jle _check_base_error
	cmp bl, byte 127
	jg _check_base_error
	cmp bl, byte 45
	je _check_base_error
	cmp bl, byte 43
	je _check_base_error
	inc rcx
	jmp _check_base_while

_check_base_success:
	pop rcx
	mov rax, 1
	ret

_check_base_error:
	pop rcx
	mov rax, 0
	ret

_get_sign:
	mov bl, [rdi]
	cmp bl, 32
	je _get_sign_inc
	cmp bl, 9
	je _get_sign_inc
	cmp bl, 10
	je _get_sign_inc
	cmp bl, 11
	je _get_sign_inc
	cmp bl, 12
	je _get_sign_inc
	cmp bl, 13
	je _get_sign_inc
	cmp bl, 45
	je _get_sign_inc_sign
	cmp bl, 43
	je _get_sign_inc
	jmp _get_sign_end

_get_sign_inc
	inc rdi
	jmp _get_sign

_get_sign_inc_sign:
	inc rdi
	imul r13, -1
	jmp _get_sign

_get_sign_end:
	ret
