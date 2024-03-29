#include <iostream>
#include "System.h"

class Screen
{
public:

private:
	bool pixels[64 * 32];
};

int main()
{
	System mainSystem;

	std::cout << "Hello World" << std::endl;
	return(0);
}