#pragma once
#ifndef _CPU_H_
#define _CPU_H_

const unsigned char maxReg = 16;
const unsigned char maxStack = 16;

class CPU
{
	public:
		// Initializes all CPU components for first time use
		bool init();

	private:
		// Keeps track of the current opcode
		unsigned short currOpcode;

		// All registers
		unsigned char regs[maxReg];
		unsigned short index;
		unsigned short pc;

		// Timers
		unsigned char delayTimer;
		unsigned char soundTimer;

		// Stack and stack pointer
		unsigned short stack[maxStack];
		unsigned char sp;
};

// Initializes all CPU components for first time use
bool CPU::init()
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

	return(true);
}

#endif