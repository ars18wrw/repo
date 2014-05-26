// 1_asm contains Check and Answer
// 4_asm contains Guess and Prelude
#include<iostream>
extern "C" bool __fastcall Prelude(int[]);
extern "C" void Guess(int[], int);
extern "C" bool __fastcall Answer(int[]);

int main()
{
	int table[81] = { 0, 0, 0, 0, 7, 0, 9, 4, 0,
		0, 0, 0, 0, 9, 0, 0, 0, 5,
		3, 0, 0, 0, 0, 5, 0, 7, 0,
		0, 0, 7, 4, 0, 0, 1, 0, 0,
		4, 6, 3, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 7, 0, 8, 0,
		8, 0, 0, 0, 0, 0, 0, 0, 0,
		7, 0, 0, 0, 0, 0, 0, 2, 8,
		0, 5, 0, 2, 6, 0, 0, 0, 0 };

	if (!Prelude(table))
	{
		std::cout << "Please, check your data.\n";
		return 0;
	}

	Guess(table, 0);
	if (!Answer(table))
	{
		std::cout << "Your table is too hard.\nTry again lately.\n";
		return 0;
	}
	for(int i = 0; i < 9; ++i)
	for (int j = 0; j < 9; ++j)
	{
		std::cout << table[i * 9 + j];
		if (j == 8)
			std::cout << std::endl;
	}
	return 0;
}