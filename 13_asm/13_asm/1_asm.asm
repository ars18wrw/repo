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
	add esi, edi


	mov eax, [ebp+16] ; eax = row
	mov edi, eax ; edi = row
	xor edx, edx
	cdq
	div ecx ; edx = row % 3
	sub edi, edx
	
	mov eax, 9
	mul edi
	add esi, eax 

	; BOX CHECK
	mov ecx, 3
@box_check:
	push ecx
	mov ecx, 3
	@box_row_check:
		cmp dword ptr[esi], ebx
		je @num_fail
		add esi, 4
	loop @box_row_check
	pop ecx
	add esi, 6 ; 9 - 3
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