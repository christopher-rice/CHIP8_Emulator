#include <iostream>
#include <iomanip>
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
	currOpcode = 0;
	index = 0;
	pc = memory::instStartAddress;
	delayTimer = 0;
	soundTimer = 0;
	sp = 0;

	// Assigns pointer to memory within system
	this->memory = memory;

	return(true);
}

// Executes a single CPU cycle
void CPU::executeCycle()
{
	// Fetch opcode

	// Grabs the current two byte instruction from memory
	unsigned short currInst = ((*memory)[pc] << 8) | (*memory)[pc + 1];

	// Prints out instruction and current address
	std::cout << std::dec << pc << ": " << "0x" << std::hex << std::setw(4) << std::setfill('0') << currInst << std::endl;

	// Decode opcode

	// Execute opcode

	// Update timers
}