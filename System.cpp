#include <fstream>
#include <iostream>
#include "System.h"

// Initializes the system and all components
bool System::init()
{
	return(cpu.init(&memory) && memory.init() && screen.init());
}

// Loads the program into memory
bool System::load(const char* filename)
{

	std::ifstream inputFile;		      // Filestream for reading binary data
	unsigned char byte;				      // Variable we'll be reading byte data into
	int index = memory::instStartAddress; // Starting address for inputting instructions into memory

	// Opens the input file in binary mode
	inputFile.open(filename, std::ios::binary);

	// Checks if file is opened correctly
	if (!inputFile.is_open())
	{
		std::cout << "File failed to open" << std::endl;
		return(false);
	}

	// Reading in binary from the input program one byte at a time
	while (inputFile.read(reinterpret_cast<char*>(&byte), sizeof(byte)))
	{
		// Writing byte data into memory
		memory[index++] = byte;
	}

	// Dumps memory into output
	memory.memdump();

	return(true);
}

// Starts the system's execution
void System::run()
{
	// Add a cycles per second tracker here

	cpu.executeCycle();

	// Continuously executes CPU cycles
	/*
	while (true)
	{
		// Executes a single CPU cycle
		cpu.executeCycle();

		// Update the screen if draw flag is set

		// Stores key press state

		std::cout << "Cycle executed" << std::endl;
	}
	*/
}