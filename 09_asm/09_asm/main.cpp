#include<iostream>
#include<windows.h>
int main()
{
	int n, i, ans = 0;
	std::cin >> n;
	BYTE * arr = new BYTE[n + 1];

	for (int i = 0; i <= n; ++i)
		arr[i] = 1;
	arr[0] = arr[1] = 0;

	_asm
	{
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
	}
	for (int i = 0; i <= n; ++i)
		if (arr[i])
			++ans;
	std::cout << ans;
	return 0;
}
