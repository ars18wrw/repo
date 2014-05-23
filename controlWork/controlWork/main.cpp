#include<iostream>
#include<cmath>
int quarter(int x, int y)
{
	int ans;
	_asm
	{
		mov eax, x	
		mov ebx, y


		cmp ebx, 0
		je __os
		cmp eax, 0
		je __os
		jg __right
		jl __left


	__right:
		cmp ebx, 0
		jg __first
		jl __fourth
	__left:
		cmp ebx, 0
		jg __second
		jl __third


	__first:
		mov eax, 1
		jmp __theend
	__second :
		mov eax, 2
		jmp __theend
	__third :
		mov eax, 3
		jmp __theend
	__fourth :
		mov eax, 4
		jmp __theend


	__os:
		mov eax, 0
	__theend:
		mov ans, eax 
	}
	return ans;
}

void complex(int x1, int y1, int x2, int y2)
{
	int ans1, ans2;
	_asm
	{
		mov eax, x1
		sub eax, x2
		mov ans1, eax

		mov eax, y1
		sub eax, y2
		mov ans2, eax
	}
	std::cout << ans1;
	if (ans2 > 0)
		std::cout << '+' << ans2 << 'i' << std::endl;
	else if (ans2 < 0)
		std::cout << ans2 << 'i' << std::endl;
}
void toTrig(double x, double y)
{
	double ro, fi;
	_asm
	{
		finit
		fld y
		fld x
		fmul st(0), st(0)
		fxch st(1)
		fmul st(0), st(0)
		fxch st(1)
		fadd st(0), st(1)
		fsqrt
		fst ro

		finit
		fld x
		fld y
		fpatan
		fst fi
	}
	std::cout << ro << "*(cos(" << fi << ")+i*sin(" << fi << ")\n";

}


void matrix(int n)
{
	int **arr1 = new int*[n];
	for (int i = 0; i < n; ++i)
		arr1[i] = new int[n];
	for (int i = 0; i < n; ++i)
	for (int j = 0; j < n; ++j)
		std::cin >> arr1[i][j];

	int **arr2 = new int*[n];
	for (int i = 0; i < n; ++i)
		arr2[i] = new int[n];
	for (int i = 0; i < n; ++i)
	for (int j = 0; j < n; ++j)
		std::cin >> arr2[j][i];

	int *ans = new int[n*n+1];

	int proz = 0, strs = 1;
	_asm
	{
		xor esi, esi
		xor edi, edi
		mov ebx, [arr1] 
		mov ecx, [arr2]

		
	__cycle:
		cmp edi, n
			je __theend
		__cont:
			inc edi
			mov ebx, [ebx]
			mov ecx, [ecx]


	__prozpart:
			mov eax, [ebx + esi*4]
			push edi
			mov edi, [ecx + esi*4]
			mul edi
			pop edi
			add proz, eax

			inc esi
			cmp esi ,n
			jne __prozpart

			mov eax, proz
			mov [ans], eax
			mov eax, 0
			mov proz, eax
			add ans, 4
			add arr2, 4
			xor esi, esi
			mov ebx, [arr1]
			mov ecx, [arr2]

			jmp __cycle


	__theend:
		push eax
		mov eax, strs
		cmp eax, n
		je __realend
		mov eax, 1
		add strs, eax
		pop eax
		add arr1, 4

		push eax
		push ebx
		mov eax, 4
		mov ebx, n		
		mul ebx
		sub arr2, eax
		mov ebx, [arr1]
		mov ecx, [arr2]


		xor edi, edi
		jmp __cont


	__realend:
		mov eax, n
		mul eax
		mov ebx, 4
		mul ebx
		sub ans, eax
	}
	std::cout << ans[0];

}





int main()
{
//	std::cout << quarter(-1, 1);
//	complex(5, 2, -1, -2);
//	toTrig(4, 3);
	matrix(2);


}