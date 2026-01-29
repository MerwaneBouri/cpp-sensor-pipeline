#include "buffer.hpp"
#include <cstdlib>
#include <fstream>


Buffer::Buffer(size_t size){
	data_.resize(size);
}

void Buffer::fillRandom(){
	for(auto& pixel: data_){
		pixel = rand() % 256;
	}
}

double Buffer::getAverage() const {
	int sum = 0;
	double avg = 0;
	for(auto i: data_){
		sum += i;
	}
	avg = static_cast<double>(sum) / size();
	return avg;
}


bool Buffer::saveToFile(const std::string& filename) const{
	std::ofstream ofs (filename);
	for(auto i: this->data_){
		ofs << i;
	}
	ofs.close();
	return 0;
}


