#ifndef WIN_H
#define WIN_H

#include "gtkmm/button.h"
#include "gtkmm/label.h"
#include <gtkmm.h>

#define MAX_CNT 10
#define MIN_CNT 0

#endif // WIN_H

/*
 * Base Window Class
 */
class Win : public Gtk::Window {
public:
    Win();
protected:
    int max_cnt = MAX_CNT;
    int min_cnt = MIN_CNT;

    Gtk::Box main_container;
    Gtk::Box btn_container;

    Gtk::Label count_label;
    Gtk::Label inc_label;
    Gtk::Label dec_label;

    Gtk::Button inc_btn;
    Gtk::Button dec_btn;

    int count = 0;

    void update_ui();
    void inc_cnt();
    void dec_cnt();
};
