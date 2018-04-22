#include "bk_event_dispatcher.h"
#include <iostream>

using namespace core::engine;

std::map<bk_event_type, std::vector<bk_module*>> bk_event_dispatcher::subs;

void bk_event_dispatcher::handle_event(bk_event ev) {
	bk_event_type type = ev.get_event_type();

	//TODO: Подумай над этим ужасом еще разок.
	for (std::vector<bk_module*>::iterator it = subs[type].begin(); it != subs[type].end(); it++) {
		(*it)->handle_event(ev);
	}
}

//Subscribe module on event
//TODO: Проверка на присутствие этого же модуля в подписчиках 
void bk_event_dispatcher::subscribe_to_events(bk_event_type _type, bk_module* _mod) {
	if (std::find(subs[_type].begin(), subs[_type].end(), _mod) != subs[_type].end()) {
		return;
	}
	subs[_type].push_back(_mod);
}