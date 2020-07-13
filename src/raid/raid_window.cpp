#include "raid_window.h"

raid::components::Window::Window() {
	set_title("Raid Application");
}

raid::components::Window::Window(raid::String title) {
	set_title(title.raw());
}
