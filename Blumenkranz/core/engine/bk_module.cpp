#include "bk_module.h"
#include <engine/events/bk_event_dispatcher.h>

using namespace core::engine;

bk_module::bk_module()
{
	bk_event ev(bk_event_type::EVENT_NONE);
	raise_event(ev);
}


bk_module::~bk_module()
{

}

void bk_module::raise_event(bk_event ev) {
	bk_event_dispatcher::handle_event(ev);
}

void bk_module::subscribe_on_events(bk_event_type type) {
	bk_event_dispatcher::subscribe_to_events(type, this);
}