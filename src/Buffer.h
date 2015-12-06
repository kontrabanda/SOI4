#ifndef Buffer_hpp
#define Buffer_hpp

#include <list>
#include <mutex>
#include <iostream>
#include <string>

using std::string;

class Buffer {
private:
	std::list<char> buffer_;
	std::mutex mtx_;

	void displayBuffer ();
	void displayPrefix (string prefix);

public:
	Buffer () 
	{}

	void push (char, string prefix);
	void pop (string prefix);
};

#endif