#pragma once
#ifndef _SYSTEM_H_
#define _SYSTEM_H_

#include "CPU.h"
#include "Memory.h"
#include "Screen.h"

class System
{
public:
	// Initializes the system and all components
	bool init();

	// Loads the program into memory
	bool load(const char* filename);

	// Starts the system's execution
	void run();

private:
	// Components of the CHIP-8 System
	CPU cpu;
	Memory memory;
	Screen screen;
};

#endif
