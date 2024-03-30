#pragma once
#ifndef _SCREEN_H_
#define _SCREEN_H_

const unsigned width = 64;
const unsigned height = 32;

class Screen
{
	public:
		// Initializes all screen components for initial use
		bool init();

	private:
		bool pixels[width * height];
};

#endif;