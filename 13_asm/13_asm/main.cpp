#include<iostream>
extern "C" void __fastcall Prepare(int[]);
extern "C" void Guess(int[], int);

int main()
{
	//int table[81];
	//for(int i = 0; i < 9; ++i)
	//for (int j = 0; j < 9; ++j)
	//	std::cin >> table[i * 9 + j];
	int table[81] = 
	  { 0, 0, 0, 0, 7, 0, 9, 4, 0,
		0, 0, 0, 0, 9, 0, 0, 0, 5,
		3, 0, 0, 0, 0, 5, 0, 7, 0,
		0, 0, 7, 4, 0, 0, 1, 0, 0,
		4, 6, 3, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 7, 0, 8, 0,
		8, 0, 0, 0, 0, 0, 0, 0, 0,
		7, 0, 0, 0, 0, 0, 0, 2, 8,
		0, 5, 0, 2, 6, 0, 0, 0, 0 };
//	std::cout << Check(table, 1, 0, 0);
	Guess(table, 0);
	//	Prepare(table);
	for(int i = 0; i < 9; ++i)
	for (int j = 0; j < 9; ++j)
	{
		std::cout << table[i * 9 + j];
		if (j == 8)
			std::cout << std::endl;
	}
}