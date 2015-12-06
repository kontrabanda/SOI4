#include "Semaphore.h"

void Semaphore::signal () {
	std::unique_lock<std::mutex> lock(mutex_);

    ++count_;
    condition_.notify_one();
}

void Semaphore::wait () {
	std::unique_lock<std::mutex> lock(mutex_);

    while(!count_)
        condition_.wait(lock);
    --count_;
}