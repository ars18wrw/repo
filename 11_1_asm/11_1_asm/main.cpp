#include<iostream>
int main()
{
	// s - sorce, sRes - destination
	char *s = new char[200], *sRes = new char[200];
	std::cin.getline(s, 200);
	_asm
	{
		mov edi, sRes
		mov cl, 1; in cl the number of repeats
		xor esi, esi
		mov edx, s
		cycle:
		inc esi
		cmp [edx+esi], byte ptr 0
		je almostend
		mov al, [edx+esi]
		cmp [edx + esi - 1], al
		jne prevEqualCheck
		inc cl
		jmp cycle

		prevEqualCheck:
		cmp cl, 1
		jne pointEqual
		mov al, byte ptr [edx + esi - 1]
		mov byte ptr[edi], al
		inc edi
		jmp cycle
		pointEqual:
		add cl, 48
		mov byte ptr[edi], cl
		inc edi
		mov al, byte ptr[edx+esi-1]
		mov byte ptr[edi],  al
		inc edi
		mov cl, 1
		jmp cycle


		almostEnd:
		cmp cl, 1
		je theEnd
		add cl, 48
		mov byte ptr[edi], cl
		inc edi
		mov al, byte ptr[edx + esi - 1]
		mov byte ptr[edi], al
		inc edi
		jmp theEndWithRep

		theEnd:
		mov al, byte ptr[edx+esi-1]
		mov byte ptr[edi], al
		inc edi
		theEndWithRep:
		mov byte ptr[edi], byte ptr 0

	}
	std::cout << sRes;
	delete[] s, sRes;
}