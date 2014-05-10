#include<iostream>
int main()
{
	int max1, max2, max3, min1, min2, cur, i = 0, n = 0;
	int arr[100];
	while (std::cin >> arr[n++]);
	--n;
	_asm
	{
		; initialization
		mov max1, INT_MIN
		mov max2, INT_MIN
		mov max3, INT_MIN
		mov min1, INT_MAX
		mov min2, INT_MAX

		mov ecx, n
		lea ebx, arr
	cycle:
		; "send" office
		mov eax, max1
		cmp [ebx], eax 
			jg _max1
		mov eax, max2
		cmp [ebx], eax
			jg _max2
		mov eax, max3
		cmp [ebx], eax
			jg _max3

	_min_check:
		mov eax, min1
		cmp eax, [ebx]
			jg _min1
		mov eax, min2
		cmp eax, [ebx]
			jg _min2

		jmp _dec_office

		; "receive" office

	_max1:
		push [ebx]
		push max1
		push max2
		pop max3
		pop max2
		pop max1
		jmp _min_check

	_max2:
		push [ebx]
		push max2
		pop max3
		pop max2
		jmp _min_check

	_max3:
		push [ebx]
		pop max3
		jmp _min_check

	_min1 :
		push [ebx]
		push min1
		pop min2
		pop min1
		jmp _dec_office

	_min2 :
		push [ebx]
		pop min2
		jmp _dec_office

	_dec_office:
		add ebx, 4

	loop cycle


		; working with results
		cmp max1, 0
		jle _exit
		
		mov eax, min1
		imul min2
		mov ecx, eax

		mov eax, max2
		imul max3
		cmp ecx, eax
		jle _exit_asm

		push min1
		push min2
		pop max3
		pop max2
	_exit_asm:


	}
	
	std::cout << max1 << " " << max2 << " " << max3;

}