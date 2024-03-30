#include "Screen.h"

// Initializes all screen components for initial use
bool Screen::init()
{
	for (bool pixel : pixels)
	{
		pixel = false;
	}

	return(true);
}