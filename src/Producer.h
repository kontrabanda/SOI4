#ifndef Producer_hpp
#define Producer_hpp

#include "Buffer.h"

class Producer {
public:
	Producer (Buffer *buf, char s, string prefix): buffer_(buf), sign_(s), prefix_(prefix) 
	{}
	void produce ();

private:
	Buffer *buffer_;
	char sign_;
	string prefix_;
};

#endif