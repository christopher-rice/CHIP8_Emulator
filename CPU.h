#pragma once
#ifndef _CPU_H_
#define _CPU_H_

// Namespace for CPU constants
namespace cpu
{
	const unsigned char maxReg = 16;
	const unsigned char maxStack = 16;
}

// Forward declaration
class Memory;

class CPU
{
	public:
		// Initializes all CPU components for first time use
		bool init(Memory* memory);

	private:
		// Memory within the system
		Memory* memory;

		// Keeps track of the current opcode
		unsigned short currOpcode;

		// All registers
		unsigned char regs[cpu::maxReg];
		unsigned short index;
		unsigned short pc;

		// Timers
		unsigned char delayTimer;
		unsigned char soundTimer;

		// Stack and stack pointer
		unsigned short stack[cpu::maxStack];
		unsigned char sp;
};

#endif