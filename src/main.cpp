#include <thread>

#include "Buffer.h"
#include "Producer.h"
#include "Consumer.h"

Producer *producerA;
Consumer *consumerA;
Buffer *buffer;

int main () {
	buffer = new Buffer();
	producerA = new Producer(buffer, 'A');
	consumerA = new Consumer(buffer);
	


	return 0;
}