#ifndef Semaphore_hpp
#define Semaphore_hpp

#include <mutex>
#include <condition_variable>

class Semaphore {
private:
    std::mutex mutex_;
    std::condition_variable condition_;
    unsigned long count_;

public:
    Semaphore()
        : count_(0)
    {}

    Semaphore(unsigned long c)
        : count_(c)
    {}

    void signal();
    void wait();
};

#endif