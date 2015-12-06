#ifndef Semaphore_hpp
#define Semaphore_hpp

#include <boost/thread/condition.hpp>
#include <boost/thread/mutex.hpp>

class Semaphore {
private:
    boost::mutex mutex_;
    boost::condition_variable condition_;
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