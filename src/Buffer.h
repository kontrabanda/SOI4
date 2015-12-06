#ifndef Buffer_hpp
#define Buffer_hpp

#include <list>
#include <mutex>
#include <iostream>
#include <string>
#include <unistd.h>

#include "Semaphore.h"

using std::string;

class Buffer {
private:
	std::list<char> buffer_;
	std::mutex mtx_;
	std::mutex producerMtx_;
	Semaphore* empty_;
	Semaphore* full_;

	int consumerCount_;

	const int BUFFER_SIZE = 7;

	void displayBuffer ();
	void displayPrefix (string prefix);

public:
	Buffer () {
		empty_ = new Semaphore(BUFFER_SIZE);
		full_ = new Semaphore(0);

		consumerCount_ = 0;
	}

	void push (char, string prefix);
	void pop (string prefix);

	~Buffer () {
		delete empty_;
		delete full_;
	}
};

#endif