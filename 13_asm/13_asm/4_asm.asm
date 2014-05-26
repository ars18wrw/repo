.386
PUBLIC _Guess
.model flat
extern _Check:proc
.code
_Guess proc
	push ebp
	mov ebp, esp
	push ebx
	push esi
	push edi
	push ecx


	mov esi, [ebp+8]
	mov edi, [ebp+12]
	cmp edi, 81
	jge @theend
	mov eax, edi
	mov ecx, 9
	xor edx, edx
	cdq
	div ecx ; edx = col
	mov ebx, eax ; ebx = row
	cmp dword ptr[esi+edi*4], 0
	je @check
	inc edi
	push edi
	push esi
	call _Guess
	add esp, 8
	jmp @ret

@check:
	push edx
	push ebx
	push ecx
	push esi
	call _Check
	pop esi
	pop ecx
	pop ebx
	pop edx

	cmp eax, 0
	jne @next
	mov dword ptr[esi+edi*4], ecx

	push ecx
	push edx
	inc edi
	push edi
	push esi
	call _Guess
	add esp, 8
	pop edx
	pop ecx

	cmp eax, 0
	je @ret
	dec edi
@next: 
	loop @check

	mov dword ptr [esi+edi*4], 0

	mov eax, 1
	jmp @ret



@theend:
	xor eax, eax	
@ret:





	pop ecx
	pop edi
	pop esi
	pop ebx
	mov esp, ebp
	pop ebp
	ret
_Guess endp
end