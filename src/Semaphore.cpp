#include "Semaphore.h"

void Semaphore::signal () {
    boost::mutex::scoped_lock lock(mutex_);
    ++count_;
    condition_.notify_one();
}

void Semaphore::wait () {
    boost::mutex::scoped_lock lock(mutex_);
    while(!count_)
        condition_.wait(lock);
    --count_;
}