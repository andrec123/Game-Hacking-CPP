#include <iostream>
#include <Windows.h>

int main()
{
	// Prompts the user to enter a Process ID
	int PID{};
	std::cout << "Enter Process ID: ";
	std::cin >> PID;

	// Opens a handle to the process with the PROCESS_ALL_ACCESS permission. If the handle is invalid, the program prints an error message and exits.
	// TODO: Figure out why PROCESS_VM_WRITE does not work.
	// Throws "WriteProcessMemory failed. GetLastError = 5" -> ERROR_ACCESS_DENIED (Access is denied.)
	HANDLE hProcess{ OpenProcess(PROCESS_ALL_ACCESS, FALSE, PID) };
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

	// Writes to the specified memory address from dataToWrite and prints success/error message
	int dataToWrite { 654321 };
	bool wpmSuccess = WriteProcessMemory(hProcess, reinterpret_cast<LPVOID>(memoryAddress), &dataToWrite, sizeof(int), NULL);
	if (wpmSuccess == FALSE) {
		std::cout << "WriteProcessMemory failed. GetLastError = " << std::dec << GetLastError() << std::endl;
		system("pause");
		return EXIT_FAILURE;
	}
	std::cout << "Wrote " << dataToWrite << " to 0x" << std::hex << std::uppercase << memoryAddress << std::endl;

	// Closes the handle to the process
	CloseHandle(hProcess);
}