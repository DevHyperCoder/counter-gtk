#include "gtkmm/application.h"
#include "iostream"
#include "win.h"

/*
 * Create a new Gtk Application with root window as `Win`
 */
int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create("com.devhypercoder.counter");
    return app->make_window_and_run<Win>(argc,argv);
}
