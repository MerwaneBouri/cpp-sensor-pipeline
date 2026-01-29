#include "buffer.hpp"
#include <iostream>

int main()
{
	Buffer buff(1000);	
	buff.fillRandom();
	std::cout << buff.getAverage() << std::endl;
	buff.saveToFile("save.txt");
	return 0;
}
