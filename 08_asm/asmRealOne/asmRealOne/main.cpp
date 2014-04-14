#include<iostream>
int main()
{
	int a, b, ans;
	std::cin >> a >> b;
	_asm
	{
		mov eax, a
		add eax, b
		mov ans, eax
	}
	std::cout << ans;
}