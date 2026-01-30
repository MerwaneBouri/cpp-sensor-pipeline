#include "buffer.hpp"
#include <iostream>
#include <chrono>
#include <iomanip>
#include <sstream>

int main()
{
	auto now = std::chrono::system_clock::now();
	auto time_t = std::chrono::system_clock::to_time_t(now);

	std::stringstream filename;
	filename << "capture_" << std::put_time(std::localtime(&time_t), "%Y%m%d_%H%M%S") << ".raw";

	Buffer buff(10000);	

	auto start = std::chrono::high_resolution_clock::now();
	buff.fillRandom();
	auto end = std::chrono::high_resolution_clock::now();
	
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

	std::cout << "Generated " << buff.size() << "bytes in " << duration.count() << "µs\n";
	
	std::cout << "Average value: " << buff.getAverage() << std::endl;

	buff.saveToFile(filename.str());
	return 0;
}
