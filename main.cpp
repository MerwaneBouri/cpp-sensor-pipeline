#include "pipeline.hpp"
#include <iostream>
#include <chrono>

int main()
{
	SensorPipeline pipeline(1000, 3);
	pipeline.start();
	std::this_thread::sleep_for(std::chrono::seconds(10));
	pipeline.stop();
	std::cout << "Captured frames. Check for 'frames_X.raw\n";	
	return 0;
}
