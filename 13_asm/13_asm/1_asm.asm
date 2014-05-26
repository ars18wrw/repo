.386
PUBLIC _Check
.model flat
.code
_Check proc
	push ebp
	mov ebp, esp
	push ebx
	push esi
	push edi
	push ecx

	mov ebx, [ebp+12]



	; ROW CHECK
	mov esi, [ebp+8]
	mov eax, [ebp+16]
	mov ecx, 4
	mul ecx
	mov ecx, 9
	mul ecx; eax = row 
	add esi, eax
@row_check:
	cmp dword ptr [esi], ebx
	je @num_fail
	add esi, 4
loop @row_check

	; COLUMN CHECK
	mov esi, [ebp+8]
	mov eax, [ebp+20]
	mov ecx, 4
	mul ecx
	add esi, eax
	mov ecx, 9
@col_check:
	cmp dword ptr [esi], ebx
	je @num_fail
	add esi, 36 ; 9*4
loop @col_check


	; WORK WITH TOP_LEFT
	mov esi, [ebp+8]
	mov eax, [ebp+20] ; eax = col
	mov edi, eax  ; edi = col
	mov ecx, 3
	xor edx, edx
	cdq
	div ecx ; edx = col%3
	sub edi, edx
	mov eax, 4
	mul edi
	add esi, eax


	mov eax, [ebp+16] ; eax = row
	mov edi, eax ; edi = row
	xor edx, edx
	cdq
	div ecx ; edx = row % 3
	sub edi, edx

	mov eax, 9
	mul edi
	mov ecx, 4
	mul ecx
	add esi, eax 

	; BOX CHECK
	mov ecx, 3
@box_check:
	push ecx
	mov ecx, 3
	@box_row_check:
		cmp dword ptr[esi], ebx
		jne @cont
		pop ecx
		jmp @num_fail

	@cont:
		add esi, 4
	loop @box_row_check
	pop ecx
	add esi, 24 ; (9 - 3)*4
loop @box_check

	xor eax, eax
	jmp @theend

@num_fail:
	mov eax, 1



	@theend:
	pop ecx
	pop edi
	pop esi
	pop ebx
	mov esp, ebp
	pop ebp
	ret
_Check endp
end