#include <thread>
#include <unistd.h>

#include "Buffer.h"
#include "Producer.h"
#include "Consumer.h"

Producer *producerA;
Consumer *consumerA;
Producer *producerB;
Consumer *consumerB;
Buffer *buffer;

void produceA ();
void produceB ();
void consumeA ();
void consumeB ();


int main () {
	buffer = new Buffer();
	producerA = new Producer(buffer, 'A', "ProducentA");
	consumerA = new Consumer(buffer, "KonsumentA");
	producerB = new Producer(buffer, 'B', "ProducentB");
	consumerB = new Consumer(buffer, "KonsumentB");
	
	std::thread prodA(produceA);
	std::thread consA(consumeA);

	std::thread prodB(produceB);
	std::thread consB(consumeB);

	prodA.join();
	consA.join();

	prodB.join();
	consB.join();

	delete producerA;
	delete producerB;
	delete consumerA;
	delete consumerB;

	return 0;
}

void produceA () {
	for (int i = 0; i < 100; ++i) {
		producerA->produce();
		usleep(400);
	}
}

void produceB () {
	for (int i = 0; i < 100; ++i) {
		producerB->produce();
		usleep(300);
	}
}

void consumeA () {
	for (int i = 0; i < 100; ++i) {
		consumerA->consume();
		usleep(400);
	}
}

void consumeB () {
	for (int i = 0; i < 100; ++i) {
		consumerB->consume();
		usleep(300);
	}
}