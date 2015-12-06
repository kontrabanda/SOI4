#include "Buffer.h"

void Buffer::push (char c, std::string prefix) {
	mtx_.lock();
	displayPrefix(prefix);
	buffer_.push_front(c);
	displayBuffer();
	mtx_.unlock();
}

void Buffer::pop (std::string prefix) {
	mtx_.lock();
	displayPrefix(prefix);
	buffer_.pop_front();
	displayBuffer();
	mtx_.unlock();
}

void Buffer::displayBuffer () {
	std::cout << "BUFFER: ";

	for (auto it = buffer_.begin(); it != buffer_.end(); ++it) {
	    std::cout << *it;
	}
	std::cout << '\n';
    std::cout << "BUFFER_SIZE: " << buffer_.size() << '\n';
}

void Buffer::displayPrefix (string prefix) {
	std::cout << prefix << ": \n";
}