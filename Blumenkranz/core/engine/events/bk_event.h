#pragma once
#include <engine/events/bk_event_type.h>

namespace core {
	namespace engine {
		class bk_event
		{
			bk_event_type type;
		public:
			bk_event();
			bk_event(bk_event_type type);
			virtual ~bk_event();

			bk_event_type get_event_type();
		};
	}
}

