#ifndef WIN_H
#define WIN_H

#include "gtkmm/label.h"
#include <gtkmm.h>

#endif // WIN_H

/*
 * Base Window Class
 */
class Win : public Gtk::Window {
public:
    Win();
protected:
    Gtk::Label hello_label;

};
