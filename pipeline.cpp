#include "pipeline.hpp"
#include <iostream>

SensorPipeline::SensorPipeline(size_t buffer_size, size_t max_queue_size ) : buffer_size_(buffer_size), max_queue_size_(max_queue_size)
{}

SensorPipeline::~SensorPipeline(){
	if(running_) stop();
}

void SensorPipeline::start(){
	running_ = true;
	producer_thread_ = std::thread(&SensorPipeline::producer, this);
	consumer_thread_ = std::thread(&SensorPipeline::consumer, this);
}

void SensorPipeline::stop(){
	running_ = false;
	cv_.notify_all();
	if(producer_thread_.joinable())
		producer_thread_.join();
	if(consumer_thread_.joinable())
		consumer_thread_.join();	
}


void SensorPipeline::producer(){
	while(running_){
		Buffer buf(buffer_size_);
		buf.fillRandom();
		{
			std::unique_lock<std::mutex> lock(mutex_);
			if(queue_.size() >= max_queue_size_) {
				queue_.pop();
				std::cout << "Dropped frame! \n";	
			}
			queue_.push(std::move(buf));	
		}
		cv_.notify_one();

		std::this_thread::sleep_for(std::chrono::milliseconds(33));
	}
}

void SensorPipeline::consumer(){
	while(running_){
		std::unique_lock<std::mutex> lock(mutex_);
		cv_.wait(lock, [this]{return !queue_.empty() || !running_;});
		if(!running_) break;
		Buffer buf = std::move(queue_.front());
		queue_.pop();
		lock.unlock();

		buf.saveToFile("frame_" + std::to_string(++counter) + ".raw");

		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}
}
