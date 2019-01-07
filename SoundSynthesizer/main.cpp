#include <iostream>
#include "olcNoiseMaker.h"

double MakeNoise(double dTime)
{
	return 0.5 * sin(440.0 * 2 * 3.14159 * dTime);
}


int main()
{
	std::wcout << "onelonecoder.com - Synthesizer Part 1" << std::endl;

	//Get all sound hardware
	std::vector<wstring> devices = olcNoiseMaker<short>::Enumerate();

	//Display findings
	for (auto d : devices) wcout << "Found output Device: " << d << std::endl;

	//Create sound machine!!
	olcNoiseMaker<short> sound(devices[0], 44100, 1, 8, 512);

	//Link noise function with sound machine
	sound.SetUserFunction(MakeNoise);

	while(1)
	{
		
	}
	
	return 0;
}
