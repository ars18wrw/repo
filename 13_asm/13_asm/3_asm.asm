.386
PUBLIC _Check@8
.model flat
.code
_Check@8 proc
	push ebp
	mov ebp, esp
	push ebx
	push esi
	push edi
	mov ebx, [ebp+12]
	mov esi, [ebp+8]
	mov eax, [esi]
	mov ecx, 9
@row_check:
	cmp eax, ebx
	je @num_fail
	add esi, 4
	mov eax, esi
loop @row_check











	mov eax, ebx
	jmp @theend

@num_fail:
	mov eax, 0



	@theend:
	pop edi
	pop esi
	pop ebx
	mov esp, ebp
	pop ebp
	ret 8
_Check@8 endp
end