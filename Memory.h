#pragma once
#ifndef _MEMORY_H_
#define _MEMORY_H_

// Names for each of the 16 registers
enum regIndex { V0, V1, V2, V3, V4, V5, V6, V7, V8, V9, VA, VB, VC, VD, VE, VF };

class Memory
{
	public:
		inline Memory() {};

	private:
		// 4K of Memory
		unsigned char mem[4096];
};

#endif