#pragma once
#ifndef _CPU_H_
#define _CPU_H_

const unsigned char maxReg = 16;
const unsigned char maxStack = 16;

class CPU
{
	public:
		// Default constructor
		inline CPU() {};

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

#endif