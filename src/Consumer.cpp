#include "Consumer.h"

void Consumer::consume () {
	buffer_->pop(prefix_);
}