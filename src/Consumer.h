#ifndef Consumer_hpp
#define Consumer_hpp

#include "Buffer.h"

class Consumer {
public:
	Consumer (Buffer *buf): buffer_(buf)
	{}
	void consume ();

private:
	Buffer *buffer_;
};

#endif