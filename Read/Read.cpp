#include <iostream>
#include <Windows.h>

int main()
{
	// Prompts the user to enter a Process ID
	int PID{};
	std::cout << "Enter Process ID: ";
	std::cin >> PID;

	// Opens a handle to the process with the PROCESS_VM_READ permission. If the handle is invalid, the program prints an error message and exits.
	HANDLE hProcess{ OpenProcess(PROCESS_VM_READ, FALSE, PID) };
	if (hProcess == NULL)
	{
		std::cout << "OpenProcess failed. GetLastError = " << std::dec << GetLastError() << std::endl;
		system("pause");
		return EXIT_FAILURE;
	}

	// Prompts the user to enter a memory address (and specifies which one from the dummy program)
	uintptr_t memoryAddress{};
	std::cout << "Enter Memory Address (varInt): ";
	std::cin >> std::hex >> memoryAddress;

	// Reads the integer at the specified memory address and prints it to the console
	int addressData{ 0 };
	ReadProcessMemory(hProcess, reinterpret_cast<LPCVOID>(memoryAddress), &addressData, sizeof(int), NULL);
	std::cout << "addressData = " << std::dec << addressData << std::endl;



	// Prompts the user to enter a memory address (and specifies which one from the dummy program)
	uintptr_t memoryAddress2{};
	std::cout << "Enter Memory Address (ptr2int): ";
	std::cin >> std::hex >> memoryAddress2;

	// Reads the memory address at the specified memory address and stores it in returnedAddress
	uintptr_t addressData2{ 0 };
	ReadProcessMemory(hProcess, reinterpret_cast<LPCVOID>(memoryAddress2), &addressData2, sizeof(uintptr_t), NULL);

	// Reads the integer at the memory address stored in returnedAddress and prints it to the console
	int addressData2_2{ 0 };
	ReadProcessMemory(hProcess, reinterpret_cast<LPCVOID>(addressData2), &addressData2_2, sizeof(int), NULL);
	std::cout << "addressData2_2 = " << std::dec << addressData2_2 << std::endl;



	// Prompts the user to enter a memory address (and specific which one from the dummy program)
	uintptr_t memoryAddress3{};
	std::cout << "Enter Memory Address (varString): ";
	std::cin >> std::hex >> memoryAddress3;

	// Reads the string at the specified memory address and prints it to the console
	std::string addressData3{};
	ReadProcessMemory(hProcess, reinterpret_cast<LPCVOID>(memoryAddress3), &addressData3, sizeof(std::string), NULL);
	std::cout << "addressData3 = " << addressData3 << std::endl;



	// Prompts the user to enter a memory address (and specific which one from the dummy program)
	uintptr_t memoryAddress4{};
	std::cout << "Enter Memory Address (arrChar): ";
	std::cin >> std::hex >> memoryAddress4;

	// Reads the string at the specified memory address and prints it to the console
	char addressData4[128]{};
	ReadProcessMemory(hProcess, reinterpret_cast<LPCVOID>(memoryAddress4), &addressData4, sizeof(addressData4), NULL);
	std::cout << "addressData4 = " << addressData4 << std::endl;

	// Closes the handle to the process
	CloseHandle(hProcess);
}