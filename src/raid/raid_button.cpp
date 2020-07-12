#include "raid_button.h"

raid::components::Button::Button() : Gtk::Button("") {}

raid::components::Button::Button(raid::String text) : Gtk::Button(text.raw()) {}