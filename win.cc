#include "win.h"

/*
 * Basic constructor to init label value
 */
Win::Win() {
    hello_label.set_label("Hello!");
    set_child(hello_label);
}
