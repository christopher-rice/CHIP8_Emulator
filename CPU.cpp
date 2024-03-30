#include "Memory.h"
#include "CPU.h"

// Initializes all CPU components for first time use
bool CPU::init(Memory* memory)
{
	// Clears all registers
	for (unsigned char reg : regs)
	{
		reg = 0;
	}

	// Clears everything in the stack
	for (unsigned short stackElem : stack)
	{
		stackElem = 0;
	}

	// Zeroing out remaining components
	unsigned short currOpcode = 0;
	unsigned short index = 0;
	unsigned short pc = 0;
	unsigned char delayTimer = 0;
	unsigned char soundTimer = 0;
	unsigned char sp = 0;

	// Assigns pointer to memory within system
	this->memory = memory;

	return(true);
}