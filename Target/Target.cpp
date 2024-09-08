#include <iostream>
#include <Windows.h>

int main()
{
	int nums { 123456 };
	std::string word { "DefaultString" };
	char sentence[128]{ "Long char array and some random text" };
	int* pNums{ &nums };
	int** ppNums{ &pNums };
	int*** pppNums{ &ppNums };

	boolean loop = true;
	while (loop)
	{
		loop = false;

		std::cout << "Process ID: " << GetCurrentProcessId() << std::endl;

		std::cout << std::endl;

		std::cout << "nums\t\t(0x" << &nums << ") = " << nums << std::endl;
		std::cout << "word\t\t(0x" << &word << ") = " << word << std::endl;
		std::cout << "sentence[128]\t(0x" << &sentence << ") = " << sentence << std::endl;

		std::cout << std::endl;

		std::cout << "pNums\t\t(0x" << &pNums << ") = 0x" << pNums << std::endl;
		std::cout << "ppNums\t\t(0x" << &ppNums << ") = 0x" << ppNums << std::endl;
		std::cout << "pppNums\t\t(0x" << &pppNums << ") = 0x" << pppNums << std::endl;

		std::cout << std::endl;

		std::cout << "Press ENTER to print again." << std::endl;
		std::cin.ignore();
		loop = true;
		std::cout << "-----------------------------------" << std::endl;
		std::cout << std::endl;
	}
}