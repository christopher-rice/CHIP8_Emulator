#include <iostream>
#include <iomanip>
#include "Memory.h"
#include "CPU.h"

// Initializes all CPU components for first time use
bool CPU::init(Memory* memory)
{
	// Clears all registers
	for (unsigned char reg : regs)
	{
		reg = 0;
	}

	// Clears everything in the stack
	for (unsigned short stackElem : stack)
	{
		stackElem = 0;
	}

	// Zeroing out remaining components
	currOpcode = 0;
	index = 0;
	pc = memory::instStartAddress;
	delayTimer = 0;
	soundTimer = 0;
	sp = 0;

	// Assigns pointer to memory within system
	this->memory = memory;

	return(true);
}

// Executes a single CPU cycle
void CPU::executeCycle()
{
	// Fetch opcode
	std::cout << "FETCH" << std::endl;

	// Grabs the current two byte instruction from memory
	unsigned short opcode = ((*memory)[pc] << 8) | (*memory)[pc + 1];

	// Prints out instruction and current address
	std::cout << std::dec << pc << ": " << "0x" << std::hex << std::setw(4) << std::setfill('0') << opcode << std::endl;

	// Decode opcode
	std::cout << "DECODE" << std::endl;

	switch (opcode & 0xF000)
	{
		case 0x0000:
			switch (opcode & 0x0FFF)
			{
				case 0x00E0:
					std::cout << "cls - clear the screen" << std::endl;
					break;

				case 0x00EE:
					std::cout << "rts - return from subroutine call" << std::endl;
					break;

				default:
					std::cout << "0x0 Instruction skiped" << std::endl;
					break;
			}

			break;

		case 0x1000:
			std::cout << "jmp NNN - Jump to address xxx" << std::endl;
			break;

		case 0x2000:
			std::cout << "jsr NNN - Jump to subroutine at address xxx" << std::endl;
			break;

		case 0x3000:
			std::cout << "skeq vx,NN - Skips instruction if reg vx == NN" << std::endl;
			break;

		case 0x4000:
			std::cout << "skne vx,NN - Skips instruction if reg vx != NN" << std::endl;
			break;

		case 0x5000:
			switch (opcode && 0x000F)
			{
				case 0x0000:
					std::cout << "skeq vx,vy - Skips instruction if reg vr == reg vy" << std::endl;
					break;

				default:
					std::cout << "0x5 Instruction skipped" << std::endl;
					break;
			}

			break;

		case 0x6000:
			std::cout << "mov vx,NN - Moves NN into reg vx" << std::endl;
			break;

		case 0x7000:
			std::cout << "add vx,NN - Adds NN into reg vx" << std::endl;
			break;

		case 0x8000:
			switch (opcode && 0x0001)
			{
				case 0x0000:
					std::cout << "mov vx,vy - Moves value in reg vy into reg vx" << std::endl;
					break;

				case 0x0001:
					std::cout << "or vx,vy - ors reg vy into reg vx" << std::endl;
					break;

				case 0x0002:
					std::cout << "and vx,vy - ands reg vy into reg vx" << std::endl;
					break;

				case 0x0003:
					std::cout << "xor vx,vy - xors reg vy into reg vx" << std::endl;
					break;

				case 0x0004:
					std::cout << "add vx,vy - adds reg vy into reg vx (carry in reg vf)" << std::endl;
					break;

				case 0x0005:
					std::cout << "sub vx,vy - subs reg vy into reg vx (borrow in reg vf [if vx > vy])" << std::endl;
					break;

				case 0x0006:
					std::cout << "shr vx - shifts vx right once (Sets vf if right most digit is 1)" << std::endl;
					break;

				case 0x0007:
					std::cout << "subn vx,vy - subs reg vy into reg vx (borrow in reg vf)" << std::endl;
					break;

				case 0x000E:
					std::cout << "shl vx - shifts vx left once (Sets vf if left most digit is 1)" << std::endl;
					break;

				default:
					std::cout << "0x8 Instruction skipped" << std::endl;
					break;
			}

			break;

		case 0x9000:
			switch (opcode & 0x000F)
			{
				case 0x0000:
					std::cout << "sne vx,vy - skips next instruction if vx != vy" << std::endl;
					break;

				default:
					std::cout << "0x9 Instruction skipped" << std::endl;
					break;
			}

			break;

		case 0xA000:
			std::cout << "mov I,NNN - sets the value of I to NNN" << std::endl;
			break;

		case 0xB000:
			std::cout << "jmp v0,NNN - Jumps to location V0 + NNN" << std::endl;
			break;

		case 0xC000:
			std::cout << "rnd vx,NN - Generates a random byte between 0 - 255 ands it with NN and puts it into vx" << std::endl;
			break;

		case 0xD000:
			std::cout << "drq vx,vy,N - Draw instruction" << std::endl;
			break;

		case 0xE000:
			switch (opcode & 0x00FF)
			{
				case 0x009E:
					std::cout << "skp vx - Skips instruction if key matching vx is pressed" << std::endl;
					break;

				case 0x00A1:
					std::cout << "sknp vx - Skips instruction if pressed key does not match vx" << std::endl;
					break;

				default:
					std::cout << "0xE Instruction skipped" << std::endl;
					break;
			}
			break;

		case 0xF000:
			switch (opcode & 0x00FF)
			{
				case 0x0007:
					std::cout << "move vx,dt - Moves delay timer value into vx" << std::endl;
					break;

				case 0x000A:
					std::cout << "move vx,k - Wait for key press and store it into vx" << std::endl;
					break;

				case 0x0015:
					std::cout << "move dt,vx - Load vx into delay timer" << std::endl;
					break;

				case 0x0018:
					std::cout << "move st,vx - Load vx into sound timer" << std::endl;
					break;

				case 0x001E:
					std::cout << "add I,vx - Adds value I and vx and puts it into I" << std::endl;
					break;

				case 0x0029:
					std::cout << "mov F,vx - Sets the location for the sprite" << std::endl;
					break;

				case 0x0033:
					std::cout << "mov B,vx - converts the data in vx into a decimal number and stores the 100s, 10s, and 1s digit into three bytes of memory starting at I" << std::endl;
					break;

				case 0x0055:
					std::cout << "mov [I],vx - loads regs v0 to vx into memory starting at I" << std::endl;
					break;

				case 0x0065:
					std::cout << "mov vx,[I] - loads the memory starting at I into regs v0 to vx" << std::endl;
					break;

				default:
					std::cout << "0xF Instruction skipped" << std::endl;
					break;
				}
				break;

		default:
			std::cout << "Generic Instruction skipped" << std::endl;
			break;
	}

	// Execute opcode

	// Update timers
}