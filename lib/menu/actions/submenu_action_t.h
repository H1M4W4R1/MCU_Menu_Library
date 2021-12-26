//
// Created by nov11 on 23.12.2021.
//

#ifndef MENULIB_SUBMENU_ACTION_T_H
#define MENULIB_SUBMENU_ACTION_T_H


#include "../action.h"
#include "../menu.h"

class submenu_action_t : action_t {
private:
    menu_t *submenu;
public:
    explicit submenu_action_t(menu_t* submenu);
    menu_t* get_menu();
};


#endif //MENULIB_SUBMENU_ACTION_T_H
