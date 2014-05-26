.386
PUBLIC @Prepare@4
.model flat
.code
@Prepare@4 proc
	push ebx
	push esi
	push edi

	mov ebx, ecx
	mov ecx, 81
@cycle:
	
	cmp [ebx], dword ptr 0
	jne @cycle_loop
	mov [ebx], dword ptr 10
	@cycle_loop:
	add ebx, 4
loop @cycle


	pop edi
	pop esi
	pop ebx
	ret 
@Prepare@4 endp
end

