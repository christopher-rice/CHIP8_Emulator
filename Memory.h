#pragma once
#ifndef _MEMORY_H_
#define _MEMORY_H_

const unsigned short maxAddress = 4096;

// Names for each of the 16 registers
enum regIndex { V0, V1, V2, V3, V4, V5, V6, V7, V8, V9, VA, VB, VC, VD, VE, VF };

class Memory
{
	public:
		// Initializes all memory components for initial use
		bool init();

	private:
		// 4K of Memory
		unsigned char mem[maxAddress];
};

// Initializes all memory components for initial use
bool Memory::init()
{
	for (unsigned char memAddress : mem)
	{
		memAddress = 0;
	}

	return(true);
}

#endif