#ifndef PIPELINE_HPP
#define PIPELINE_HPP

#include "buffer.hpp"
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>

class SensorPipeline {
public: 
	SensorPipeline(size_t buffer_size, size_t max_queue_size = 5);
	~SensorPipeline();
	
	void start();
	void stop();

private:
	void producer();
	void consumer();

	size_t buffer_size_;
	size_t max_queue_size_;

	std::queue<Buffer> queue_;
	std::mutex mutex_;
	std::condition_variable cv_;

	std::atomic<bool> running_;
	std::thread producer_thread_;
	std::thread consumer_thread_;

	size_t counter = 0;
};

#endif
