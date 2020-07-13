#include "raid_button.h"

raid::components::Button::Button() : Gtk::Button("") {
	this->initHandlers();
}

raid::components::Button::Button(raid::String text) : Gtk::Button(text.raw()) {
	this->initHandlers();
}

void raid::components::Button::initHandlers() {
	signal_clicked().connect(sigc::mem_fun(*this, &raid::components::Button::onClick));
}