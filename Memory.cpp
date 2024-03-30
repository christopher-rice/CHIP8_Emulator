#include <iostream>
#include <iomanip>
#include "Memory.h"

// Initializes all memory components for initial use
bool Memory::init()
{
	for (unsigned char memAddress : mem)
	{
		memAddress = 0;
	}

	return(true);
}

// Prints out all data within memory
void Memory::memdump()
{
	for (int i = 0; i < memory::maxAddress; i++)
	{
		std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)mem[i] << " ";

		if ((i + 1) % 16 == 0)
		{
			std::cout << std::endl;
		}
	}
}

// Index operator overload
unsigned char& Memory::operator[](unsigned short index)
{
	if (index >= memory::maxAddress)
	{
		std::cout << "ERROR: Memory address out of bounds" << std::endl;
		exit(0);
	}

	return(mem[index]);
}