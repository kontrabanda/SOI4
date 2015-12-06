#include  "Producer.h"

void Producer::produce () {
	buffer_->push(sign_, prefix_);
}