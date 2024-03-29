#include <iostream>
#include "System.h"

// The main CHIP-8 system for emulation
System mainSystem;

int main()
{
	// Setup
	/*
	 * This is where we want to setup any of our graphics
	 * and sound subsystems
	 */

	// Initialize
	/*
	 * Initializes the system and loads the program into
	 * memory
	 */

	bool initFlag = mainSystem.init();

	if (initFlag)
	{
		std::cout << "INIT SUCCESS" << std::endl;
	}
	else
	{
		std::cout << "INIT FAILED" << std::endl;
	}

	bool loadFlag = mainSystem.load("TestRoms\\test_opcode.ch8");

	// Run
	/*
	 * Actually runs the system
	 */



	return(0);
}