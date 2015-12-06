#include  "Producer.h"

void Producer::produce () {
	buffer_->push(sign_);
}