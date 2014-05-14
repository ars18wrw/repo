#include<iostream>
int n, i;
double x, y, z, ans = 0;
int main()
{
	std::cin >> n;
	std::cin >> x >> y >> z;
	_asm
	{
		fld1 ; //1 st(3) for the "highest" item
		fld1 ; //1 st(2) for the answer
		fldz ; //0 st(1) for the last summand
		fld1 ; //1 st(0) x*y in some power
		


		; // n>0
		mov ecx, n
		cmp ecx, 0
		je _end

	_for:
		; //some work with the "highest" item
		fmul x
		fmul y
		fmul st(3), st(0)
		fxch st(3)
		fdiv z

		; //in st1 - the last summand
		fadd st(1), st(0)
		fxch st(3)

		; //st2 contains the answer
		fxch st(1)
		fmul st(2), st(0)
		fxch st(1)
	loop _for
		jmp _end
	

	_end:
		fxch st(2)
		fst ans

	}
	std::cout << ans;
}

