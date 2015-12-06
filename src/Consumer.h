#ifndef Consumer_hpp
#define Consumer_hpp

#include "Buffer.h"

class Consumer {
public:
	Consumer (Buffer *buf, std::string prefix): buffer_(buf), prefix_(prefix)
	{}
	void consume ();

private:
	Buffer *buffer_;
	std::string prefix_;
};

#endif