#include "win.h"
#include "gtkmm/enums.h"
#include "sigc++/functors/mem_fun.h"
#include <iostream>
#include <stdexcept>
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

    min_cnt_entry.set_placeholder_text("0 (min)");
    max_cnt_entry.set_placeholder_text("10 (max)");

    min_cnt_entry.signal_changed().connect(sigc::mem_fun(*this,&Win::update_min_cnt));
    max_cnt_entry.signal_changed().connect(sigc::mem_fun(*this,&Win::update_max_cnt));

    entry_container.set_homogeneous();
    entry_container.append(min_cnt_entry);
    entry_container.append(max_cnt_entry);

    main_container.set_orientation(Gtk::Orientation::VERTICAL);
    main_container.append(btn_container);
    main_container.append(entry_container);
    main_container.append(entry_status_label);
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

    entry_status_label.set_label(entry_status);

    if(entry_status != "") {
        inc_btn.set_sensitive(false);
        dec_btn.set_sensitive(false);

        return;
    }

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

void Win::update_max_cnt() {
    auto max_str = max_cnt_entry.get_text();

    try {
        max_cnt = std::stoi(max_str);
        entry_status = "";
    } catch(std::invalid_argument const &e) {
        entry_status = "Invalid max count!";
    } catch(std::out_of_range const &e ) {
        entry_status = "Too long for me!";
    }

    update_ui();
}

void Win::update_min_cnt() {
    auto min_str = min_cnt_entry.get_text();

    try {
        min_cnt = std::stoi(min_str);
        entry_status = "";
    } catch(std::invalid_argument const &e) {
        entry_status = "Invalid min count!";
    } catch(std::out_of_range const &e ) {
        entry_status = "Too long for me!";
    }

    update_ui();
}

