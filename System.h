#pragma once
#ifndef _SYSTEM_H_

#include "CPU.h"
#include "Memory.h"

class System
{
public:

private:
	// Components of the CHIP-8 System
	CPU cpu;
	Memory memory;
};

#endif
