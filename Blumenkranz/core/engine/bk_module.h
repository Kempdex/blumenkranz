#pragma once
#include <engine\events\bk_event.h>

namespace core {
	namespace engine {
		class bk_module
		{
		public:
			bk_module();
			virtual ~bk_module();

			void raise_event(bk_event ev);
			void subscribe_on_events(bk_event_type type);

			//Every module listen to events in one's own way
			virtual void handle_event(bk_event ev) = 0;
		};
	}
}