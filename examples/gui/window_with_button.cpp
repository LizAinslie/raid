#include <iostream>

#include <gtkmm-3.0/gtkmm/application.h>

#include <raid/raid_window.h>
#include <raid/raid_button.h>

class MyButton : public raid::components::Button {
public:
	MyButton() : raid::components::Button(raid::String((char*)"Hello world!")) {};

	void onClick() override {
		std::cout << "Hello, world!" << std::endl;
	}
};

int main(int argc, char** argv) {
	auto app = Gtk::Application::create(argc, argv, "tech.raildev.raid.example");

	raid::components::Window window;
	MyButton btn;

	window.add(btn);
	btn.show();

	//Shows the window and returns when it is closed.
	return app->run(window);
}