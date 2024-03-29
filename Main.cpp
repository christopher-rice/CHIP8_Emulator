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

	// Initializes the system and all of it's components
	if (!mainSystem.init())
	{
		std::cout << "ERROR: Failed to initialize system" << std::endl;
		exit(0);
	}

	// Program that we will run
	const char* inputProgram = "TestRoms\\test_opcode.ch8";

	// Loads program into memory
	if (!mainSystem.load(inputProgram))
	{
		std::cout << "ERROR: Failed to load " << inputProgram << " into memory" << std::endl;
		exit(0);
	}

	// Run
	/*
	 * Actually runs the system
	 */



	return(0);
}