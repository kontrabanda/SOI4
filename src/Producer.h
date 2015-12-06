#ifndef Producer_hpp
#define Producer_hpp

#include "Buffer.h"

class Producer {
public:
	Producer (Buffer *buf, char s) : buffer_(buf), sign_(s) 
	{}
	void produce ();

private:
	Buffer *buffer_;
	char sign_;
};

#endif