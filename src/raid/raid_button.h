#pragma once

#include <gtkmm-3.0/gtkmm/button.h>

#include <string>

#include "raid_string.h"

namespace raid {
	namespace components {
		class Button : public Gtk::Button {
		public:
			Button();
			explicit Button(raid::String text);
		};
	}
}
