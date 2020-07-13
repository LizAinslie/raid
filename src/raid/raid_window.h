#pragma once

#include <gtkmm-3.0/gtkmm/window.h>

#include "raid_string.h"

namespace raid {
	namespace components {
		class Window : public Gtk::Window {
		public:
			Window();
			explicit Window(raid::String title);
		};
	}
}