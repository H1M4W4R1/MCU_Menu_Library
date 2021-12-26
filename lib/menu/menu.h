//
// Created by nov11 on 23.12.2021.
//

#ifndef MENULIB_MENU_H
#define MENULIB_MENU_H
#include "menu_option.h"
#include <vector>

class menu_t;

class menu_t {
private:
    std::vector<menu_option_t*> options = {};
public:
    menu_t* add_option(menu_option_t* option);

    void render(int start = 0, int count = 2, int selected = 0);
    void execute_option(int i, action_type_t actionType, i_action_metadata* metadata);

    int available_options_count();
};


#endif //MENULIB_MENU_H
