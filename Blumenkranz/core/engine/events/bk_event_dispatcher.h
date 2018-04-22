#pragma once
#include <map>
#include <vector>
#include <algorithm>

#include <engine/events/bk_event.h>
#include <engine/events/bk_event_type.h>
#include <engine/bk_module.h>

namespace core {
	namespace engine {
		class bk_event_dispatcher
		{
			//
			static std::map<bk_event_type, std::vector<bk_module*>> subs;
			bk_event_dispatcher() {} //without instance
		public:
			
			static void handle_event(bk_event ev);
			static void subscribe_to_events(bk_event_type _type, bk_module* _mod);
		};
	}
}

