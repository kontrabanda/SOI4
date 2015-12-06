#ifndef Buffer_hpp
#define Buffer_hpp

#include <list>
#include <mutex>
#include <iostream>

class Buffer {
private:
	std::list<char> buffer_;
	std::mutex mtx_;

public:
	Buffer () 
	{}

	void push (char);
	void pop ();
	void displayBuffer ();
};

#endif