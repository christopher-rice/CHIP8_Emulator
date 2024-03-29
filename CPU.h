#pragma once
#ifndef _CPU_H_
#define _CPU_H_

class CPU
{
	public:
		// Default constructor
		inline CPU() {};

	private:
		// Keeps track of the current opcode
		unsigned short currOpcode;

		// General purpose and carry registers
		unsigned char regs[16];
};

#endif