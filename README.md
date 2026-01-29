# C++ Sensor Pipeline
Rehabilitating C++ skills with modern C++17 (smart pointers, RAII, chrono) 
while building a synthetic sensor data pipeline.

## Progress
- [x] Day 1: Buffer class with RAII memory management
- [ ] Day 2: Timestamps and performance benchmarking
- [ ] Day 3: Multi-threading (producer/consumer)
- [ ] Day 4: ROS 2 integration


## Build
```bash
g++ -std=c++17 -Wall -Wextra -o buffer_test main.cpp buffer.cpp
