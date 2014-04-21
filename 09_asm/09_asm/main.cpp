#include<iostream>
#include<windows.h>
int main()
{
	int n, i, ans = 0;
	std::cin >> n;
	BYTE * arr = new BYTE[n + 1];
	_asm
	{
		; filling array
		mov ecx, n
		mov esi, arr
	fillArr:
		mov byte ptr[esi], 1
		inc esi
	loop fillArr
		mov esi, arr
		mov byte ptr[esi], 0
		inc esi
		mov byte ptr[esi], 0


		mov i, 2
	begin:
		mov eax, i
		mul i
		cmp eax, n
		jg _end
		mov esi, i
		cmp arr[esi], 0
		je _next
		mov eax, i
		add eax, i
	cycle :
		cmp eax, n
		jg _next
		mov esi, arr
		add esi, eax
		mov byte ptr[esi], 0
		add eax, i
		jmp cycle
	_next :
		inc i
		jmp begin
	_end :

		; counting
		mov esi, arr
		mov ecx, n
		countAns:
		cmp byte ptr[esi], 0
		je fail
		inc ans
	fail: 
		inc esi
		loop countAns

	}
	std::cout << ans;
	return 0;
}
