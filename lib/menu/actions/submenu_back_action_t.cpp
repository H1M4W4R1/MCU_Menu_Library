//
// Created by nov11 on 23.12.2021.
//

#include "submenu_back_action_t.h"
#include "../menu_common.h"

void menu_go_to_previous(action_t* action, i_action_metadata* metadata) {
    menu_common_t::go_back();
}

submenu_back_action_t::submenu_back_action_t() : action_t(menu_go_to_previous, ON_PRESS){

}

