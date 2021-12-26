//
// Created by nov11 on 23.12.2021.
//

#include "submenu_action_t.h"
#include "../menu_common.h"

void open_submenu(action_t* action, i_action_metadata* metadata)
{
    // Convert action to proper type
    auto thisAction = (submenu_action_t*) action;

    // Open menu
    menu_common_t::open_menu(thisAction->get_menu());
}

submenu_action_t::submenu_action_t(menu_t *submenu) : action_t(&open_submenu, action_type_t::ON_PRESS) {
    this->submenu = submenu;
}

menu_t *submenu_action_t::get_menu() {
    return this->submenu;
}
