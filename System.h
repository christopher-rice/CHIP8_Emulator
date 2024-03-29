#pragma once
#ifndef _SYSTEM_H_

#include <fstream>
#include <iostream>
#include <iomanip>
#include "CPU.h"
#include "Memory.h"
#include "Screen.h"

class System
{
public:
	// Initializes the system and all components
	bool init();

	// Loads the program into memory
	bool load(const char* filename);

	// Starts the system's execution
	void run();

private:
	// Components of the CHIP-8 System
	CPU cpu;
	Memory memory;
	Screen screen;
};

// Initializes the system and all components
bool System::init()
{
	return(cpu.init() && memory.init() && screen.init());
}

// Loads the program into memory
bool System::load(const char* filename)
{
	std::ifstream inputFile;

	inputFile.open(filename, std::ios::binary);

	if (!inputFile.is_open())
	{
		std::cout << "File failed to open" << std::endl;
		return(false);
	}

	unsigned char byte;
	unsigned char byteArray[478];
	int i = 0;

	while (inputFile.read(reinterpret_cast<char*>(&byte), sizeof(byte)))
	{
		byteArray[i++] = byte;
	}

	for (int i = 0; i < 478; i++)
	{
		std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)byteArray[i] << " ";

		if ((i + 1) % 16 == 0)
		{
			std::cout << std::endl;
		}
	}

	return(true);
}

#endif
