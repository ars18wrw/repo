//	write sizes and then the array. sizes should be natural


#include<iostream>
int main()
{
	/* n, m for sizes, ones for the greatest number of ones,
	ans for string should be mentiones in the answer,
	itStr for current string in the cycleTwo */





	int n, m, ones, ans, itStr;
	std::cin >> n >> m;
	int **arr = new int*[n];
	for (int i = 0; i < n; ++i)
		arr[i] = new int[m];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			std::cin >> arr[i][j];
	int *strs = new int[n*m+1];
	_asm
	{
		; preparing
		mov ones, 0
		mov ans, 0
		mov itStr, 0
		mov ebx, [strs]
		mov edx, -1

		xor esi, esi
		mov ebx, [arr]
		mov ebx, [ebx]
		mov eax, n
		mul m
		mov ecx, eax

	cycle:
		push ecx
		mov ecx, 32
		mov edx, 1b
		xor eax, eax


	div_cycle:
		test [ebx+esi*4], edx
		jz _continue_of_div 
		inc eax
	_continue_of_div:
		shl edx, 1
		loop div_cycle
		pop ecx

		mov [ebx + esi * 4], eax
		cmp eax, ones
		jle _again
		mov ones, eax

	_again:
		inc esi
		cmp esi, m
		jne _ret_to_loop
		add arr, 4
		mov ebx, [arr]
		mov ebx, [ebx]
		xor esi, esi
	_ret_to_loop:
		loop cycle



		mov eax, 4
		mul n
		sub arr, eax





		xor esi, esi
		mov ebx, [arr]	
		mov ebx, [ebx]

		mov eax, n
		mul m
		mov ecx, eax

		mov edx, strs

	cycleTwo :
		mov eax, ones
		cmp [ebx + esi * 4], eax
		jne _cont_cycleTwo
		mov eax, itStr
		cmp [edx], eax
		je _cont_cycleTwo
		mov eax, itStr
		add edx, 4
		mov [edx], eax 
		inc ans

	_cont_cycleTwo:
		inc esi
		cmp esi, m
		jne _ret_to_loopTwo
		add arr, 4
		inc itStr
		mov ebx, [arr]
		mov ebx, [ebx]
		xor esi, esi

	_ret_to_loopTwo:
		loop cycleTwo



		mov eax, 4
		mul n
		sub arr, eax


	}

	for (int i = 1; i < ans + 1; ++i)
		std::cout << strs[i] + 1 << std::endl;

	for (int i = 0; i < n; ++i)
		delete[] arr[i];
	delete[] arr;


}