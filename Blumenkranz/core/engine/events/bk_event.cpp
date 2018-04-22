#include "bk_event.h"

using namespace core::engine;

bk_event::bk_event()
{

}

bk_event::bk_event(bk_event_type type) {
	this->type = type;
}

bk_event::~bk_event()
{

}


bk_event_type bk_event::get_event_type() {
	return this->type;
}

