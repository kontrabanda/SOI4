#include <thread>
#include <unistd.h>

#include "Buffer.h"
#include "Producer.h"
#include "Consumer.h"

Producer *producerA;
Consumer *consumerA;
Buffer *buffer;

void produceA ();
void produceB ();
void consumeA ();
void consumeB ();


int main () {
	buffer = new Buffer();
	producerA = new Producer(buffer, 'A', "ProducentA");
	consumerA = new Consumer(buffer, "KonsumentA");
	
	std::thread prodA(produceA);
	std::thread consA(consumeA);

	prodA.join();
	consA.join();

	return 0;
}

void produceA () {
	for (int i = 0; i < 100; ++i) {
		producerA->produce();
		usleep(400);
	}
}

void produceB () {

}

void consumeA () {
	for (int i = 0; i < 100; ++i) {
		consumerA->consume();
		usleep(200);
	}
}

void consumeB () {

}