#include "Buffer.h"

void Buffer::push (char c, std::string prefix) {
	empty_->wait();

	producerMtx_.lock();

	displayPrefix(prefix);
	buffer_.push_front(c);
	displayBuffer();
	
	producerMtx_.unlock();

	full_->signal();
}

void Buffer::pop (std::string prefix) {
	full_->wait();

	mtx_.lock();

	++consumerCount_;
	if (consumerCount_ == 1)
		producerMtx_.lock();

	displayPrefix(prefix);
	buffer_.pop_front();
	displayBuffer();	

	--consumerCount_;
	if (consumerCount_ == 0)
		producerMtx_.unlock();

	mtx_.unlock();

	empty_->signal();
}

void Buffer::displayBuffer () {
	std::cout << "BUFFER: ";

	for (auto it = buffer_.begin(); it != buffer_.end(); ++it) {
	    std::cout << *it;
	}
	std::cout << '\n';
    std::cout << "BUFFER_SIZE: " << buffer_.size() << "\n\n";
}

void Buffer::displayPrefix (string prefix) {
	std::cout << prefix << ": \n";
}