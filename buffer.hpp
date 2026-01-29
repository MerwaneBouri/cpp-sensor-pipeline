#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <vector>
#include <string>

class Buffer {
public: 
	explicit Buffer(size_t size);

	void fillRandom();

	double getAverage() const;

	bool saveToFile(const std::string& filename) const;

	size_t size() const { return data_.size(); }

private:
	std::vector<uint8_t> data_;
};

#endif
