#include "win.h"
#include "gtkmm/enums.h"
#include "sigc++/functors/mem_fun.h"
#include <string>

/*
 * Basic constructor to init label value
 */
Win::Win() {

    inc_btn.signal_clicked().connect(
        sigc::mem_fun(*this,&Win::inc_cnt)
    );

    inc_label.set_label("INCREMENT");
    inc_btn.set_child(inc_label);

    dec_btn.signal_clicked().connect(
        sigc::mem_fun(*this,&Win::dec_cnt)
    );

    dec_label.set_label("DECREMENT");
    dec_btn.set_child(dec_label);

    btn_container.set_orientation(Gtk::Orientation::HORIZONTAL);
    btn_container.set_homogeneous();
    btn_container.append(inc_btn);
    btn_container.append(dec_btn);

    main_container.set_orientation(Gtk::Orientation::VERTICAL);
    main_container.append(btn_container);
    main_container.append(count_label);

    set_child(main_container);

    update_ui();
}

void Win::inc_cnt() {
    count +=1;
    update_ui();
}

void Win::dec_cnt() {
    count -=1;
    update_ui();
}

void Win::update_ui() {
    // int -> str and update label
    std::string str_cnt = std::to_string(count);
    count_label.set_label(str_cnt);

    // Set both buttons to enabled state
    inc_btn.set_sensitive();
    dec_btn.set_sensitive();

    if (count == max_cnt) {
        inc_btn.set_sensitive(false);
    }

    if(count == min_cnt) {
        dec_btn.set_sensitive(false);
    }
}
