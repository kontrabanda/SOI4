#include "Buffer.h"

void Buffer::push (char c) {
	mtx_.lock();
	buffer_.push_front(c);
	mtx_.unlock();
}

void Buffer::pop () {
	mtx_.lock();
	buffer_.pop_front();
	mtx_.unlock();
}

void Buffer::displayBuffer () {
	for (auto it = buffer_.begin(); it != buffer_.end(); ++it) {
	    std::cout << *it;
	}

    std::cout << '\n';
}