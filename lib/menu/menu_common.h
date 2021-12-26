//
// Created by nov11 on 23.12.2021.
//

#ifndef MENULIB_MENU_COMMON_H
#define MENULIB_MENU_COMMON_H

#include <stack>
#include "menu.h"
#include "menu_option.h"
#include "action.h"
#include "actions/submenu_action_t.h"
#include "actions/submenu_back_action_t.h"

#define ACTION(name) void name(action_t* action, i_action_metadata* metadata)
#define MENU_SUBMENU_OPTION(title, submenu) (new menu_option_t(title))->add_listener((action_t*) submenu)
#define MENU_SIMPLE_OPTION(title, listener, type) (new menu_option_t(title))->add_listener(new action_t(listener, type))
#define MENU_INCREASE_DECREASE_OPTION(title, listener_increase, listener_decrease) (new menu_option_t(title))->add_listener(new action_t(listener_increase, action_type_t::ON_INCREASE))->add_listener(new action_t(listener_decrease, action_type_t::ON_DECREASE))
#define MENU_CHANGE_OPTION(title, listener) (new menu_option_t(title))->add_listener(new action_t(listener, action_type_t::ON_CHANGE))
#define MENU_BACK_OPTION(title) (new menu_option_t(title))->add_listener((action_t*) new submenu_back_action_t()))


class menu_common_t {

private:
    static inline std::vector<menu_t*> path{}; // Represents current menu path
    inline static int current_option_index = 0; // Current option
    inline static int current_render_index = 0; // Current option to render as first
    inline static int rendered_options_count = 2; // How many options to render
public:
    static void open_menu(menu_t* menu); // Open specified menu
    static void go_back(int amount = 1); // Go back to previous menu
    static void next(); // Go to next option
    static void previous(); // Go to previous option
    static void refresh(); // Refresh current menu
    static void execute(action_type_t type, i_action_metadata* metadata); // Execute option's action

};


#endif //MENULIB_MENU_COMMON_H
