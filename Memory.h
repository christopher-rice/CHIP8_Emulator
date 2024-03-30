#pragma once
#ifndef _MEMORY_H_
#define _MEMORY_H_

// Namespace for Memory constants
namespace memory
{
	const unsigned short instStartAddress = 512;
	const unsigned short maxAddress = 4096;
}

// Names for each of the 16 registers
enum regIndex { V0, V1, V2, V3, V4, V5, V6, V7, V8, V9, VA, VB, VC, VD, VE, VF };

class Memory
{
	public:
		// Initializes all memory components for initial use
		bool init();

		// Prints out all data within memory
		void memdump();

		// Index operator overload
		unsigned char& operator[](unsigned short index);

	private:
		// 4K of Memory
		unsigned char mem[memory::maxAddress];
};

#endif